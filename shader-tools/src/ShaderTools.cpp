/*
 * Copyright 2016 GoPro Inc.
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include "ShaderTools.h"
#include "FileUtil.h"
#include <filesystem>
#include <regex>
#include <fstream>
using namespace std;
using namespace ngfx;
namespace fs = std::filesystem;

#ifdef _WIN32
    #define PATCH string("patch.exe")
    #define GLSLANG_VALIDATOR string("glslangValidator.exe")
    #define SPIRV_CROSS string("spirv-cross.exe")
#else
    #define PATCH string("patch")
    #define GLSLANG_VALIDATOR string("glslangValidator")
    #define SPIRV_CROSS string("spirv-cross")
#endif

#define CHECK_TIMESTAMPS(srcFileName, targetFileName) \
    time_t srcTimeStamp = getmtime(srcFileName); \
    time_t targetTimeStamp = getmtime(targetFileName); \
    if (srcTimeStamp <= targetTimeStamp) \
        return 0

ShaderTools::ShaderTools() {
    verbose = (string(getenv("V"))=="1");
    defaultIncludePaths = { "ngfx/data/shaders", "nodegl/data/shaders" };
}

int ShaderTools::cmd(string str) {
    if (verbose) { printf(">> %s\n", str.c_str()); }
    else str += " > /dev/null 2>&1";
    return system(str.c_str());
}

bool ShaderTools::findIncludeFile(const string& includeFilename, const vector<string> &includePaths,
        string& includeFile) {
    for (const string& includePath : includePaths) {
        fs::path filename = includePath  / fs::path(includeFilename);
        if (fs::exists(filename)) {
            includeFile = filename;
            return true;
        }
    }
    return false;
}

string ShaderTools::preprocess(const string& dataPath, const string& inFile) {
    string contents = "";
    vector<string> includePaths = defaultIncludePaths;
    includePaths.push_back(dataPath);
    istringstream sstream(inFile);
    string line;
    while (std::getline(sstream, line)) {
        smatch matchIncludeGroups;
        bool matchInclude = regex_search(line, matchIncludeGroups, regex("#include \"([^\"]*)"));
        if (matchInclude) {
            string includeFilename = matchIncludeGroups[1];
            string includeFilePath;
            findIncludeFile(includeFilename, includePaths, includeFilePath);
            contents += FileUtil::readFile(includeFilePath);
        }
        else {
            contents += line;
        }
    }
    return contents;
}

time_t ShaderTools::getmtime(const string& filename) {
    if (!fs::exists(filename)) { return 0; }
    auto ftime = fs::last_write_time(filename);
    return fs::file_time_type::clock::to_time_t(ftime);
}

int ShaderTools::compileShaderGLSL(string filename, const string& defines, const string& outDir, vector<string>& outFiles) {
    string parentPath = fs::path(filename).parent_path();
    filename = fs::path(filename).filename();
    string inFileName = fs::path(parentPath + "/" + filename);
    string outFileName = fs::path(outDir + "/" + filename + ".spv");
    CHECK_TIMESTAMPS(inFileName, outFileName);

    ofstream outFile(fs::path(outDir + "/" + filename));
    string contents = preprocess(parentPath, inFileName);
    outFile<< contents;
    outFile.close();
    int result = cmd(GLSLANG_VALIDATOR+" " + defines + " -V "+
                     fs::path(outDir + "/" + filename).string()+
                     fs::path(" -o"+ outFileName).string());
    if (result == 0) {
        printf("compiled file: %s\n", filename.c_str());
    }
    else {
        fprintf(stderr, "ERROR: cannot compile file: %s\n", filename.c_str());
    }
    outFiles.push_back(outFileName);
    return result;
}

int ShaderTools::compileShaderMTL(const string& file, const string& defines, string outDir, vector<string> &outFiles) {
    string strippedFilename = FileUtil::splitExt(fs::path(file).filename())[0];
    string inFileName = fs::path(outDir +"/" + strippedFilename + ".metal");
    string outFileName = fs::path(outDir + "/" + strippedFilename + ".metallib");
    CHECK_TIMESTAMPS(inFileName, outFileName);

    string debugFlags = "-gline-tables-only -MO";
    int result = cmd(
          "xcrun -sdk macosx metal {debugFlags} -c {inFileName} -o {outDir}/{filename}.air && "
          "xcrun -sdk macosx metallib {outDir}/{filename}.air -o {outFileName}"
    );
    if (result == 0)
        printf("compiled file: %s\n", file.c_str());
    else
        fprintf(stderr, "ERROR: cannot compile file: %s\n", file.c_str());
    outFiles.push_back(outFileName);
    return result;
}

int ShaderTools::compileShaderHLSL(const string& file, const string& defines, string outDir, vector<string>& outFiles) {
    string strippedFilename = FileUtil::splitExt(fs::path(file).filename())[0];
    string inFileName = outDir+"/"+strippedFilename +".hlsl";
    string outFileName = outDir +"/" +strippedFilename +".dxc";
    CHECK_TIMESTAMPS(inFileName, outFileName);

    string shaderModel = "";
    if (strstr(inFileName.c_str(), ".vert")) shaderModel = "vs_5_0";
    else if (strstr(inFileName.c_str(), ".frag")) shaderModel = "ps_5_0";
    else if (strstr(inFileName.c_str(), ".comp")) shaderModel = "cs_5_0";
    int result = cmd("dxc.exe /T "+shaderModel+" /Fo "+outFileName+" "+inFileName);
    if (result == 0)
        printf("compiled file: %s\n", file.c_str());
    else
        fprintf(stderr, "ERROR: cannot compile file: %s\n", file.c_str());
    outFiles.push_back(outFileName);
    return result;
}

int ShaderTools::convertShader(const string& file, const string& extraArgs, string outDir, string fmt, vector<string>& outFiles) {
    string strippedFilename = FileUtil::splitExt(fs::path(file).filename())[0];
    string inFileName = fs::path(outDir + "/" + strippedFilename + ".spv");
    string outFileName = fs::path(outDir + "/" + strippedFilename + (fmt == "msl" ? ".metal" : ".hlsl"));
    outFiles.push_back(outFileName);
    CHECK_TIMESTAMPS(inFileName, outFileName);

    string args = (fmt == "msl" ? "--msl" : "--hlsl --shader-model 60") + extraArgs;
    int result = cmd(SPIRV_CROSS + " " + args + " " + inFileName + " " + "--output" + " " + outFileName);
    if (result == 0)
        printf("converted file: %s to %s\n", inFileName.c_str(), outFileName.c_str());
    else
        fprintf(stderr, "ERROR: cannot convert file: %s\n", file.c_str());
    return result;
}

int ShaderTools::genShaderReflectionGLSL(const string& file, string outDir) {
    string filename = FileUtil::splitExt(fs::path(file).filename())[0];
    string inFileName = outDir + "/" + filename + ".spv";
    string outFileName = outDir + "/" + filename + ".spv.reflect";
    CHECK_TIMESTAMPS(inFileName, outFileName);

    int result = cmd(SPIRV_CROSS+" "+inFileName+" --reflect --output "+outFileName);

    inFileName = outDir + "/" + filename + ".spv.reflect";
    outFileName = inFileName;

    string reflectData = json.loads(readFile(inFileName));

    ofstream outFile(outFileName);
    contents = json.dumps(reflectData, sort_keys=True, indent=4, separators=(',', ': '));
    outFile.write(contents);
    outFile.close();

    if (result == 0)
        printf("generated reflection map for file: %s\n", file.c_str());
    else {
        fprintf(stderr, "ERROR: cannot generate reflection map for file: %s", file.c_str());
    }

    return result;
}

#if 0
def findMetalReflectData(metalReflectData, name):
    for data in metalReflectData:
        if data[1] == name: return data
        elif name in data[0]: return data
    return None

def patchShaderReflectionDataMSL(file, reflectData, ext):
    metalFile = open(f"{file}", 'r')
    metalContents = metalFile.read()
    metalReflectData = {}
    if ext == '.vert':
        metalReflectData['attributes'] = re.findall(r'([^\s]*)[\s]*([^\s]*)[\s]*\[\[attribute\(([0-9]+)\)\]\]', metalContents)
    metalReflectData['buffers'] = re.findall(r'([^\s]*)[\s]*([^\s]*)[\s]*\[\[buffer\(([0-9]+)\)\]\]', metalContents)
    metalReflectData['textures'] = re.findall(r'([^\s]*)[\s]*([^\s]*)[\s]*\[\[texture\(([0-9]+)\)\]\]', metalContents)
    metalFile.close()

    textures, ubos, ssbos, images, types = getDictEntries(reflectData, ['textures', 'ubos','ssbos','images','types'])
    numDescriptors = len(textures) + len(images) + len(ubos) + len(ssbos)

    #update input bindings
    if ext == '.vert':
        inputs = getDictEntry(reflectData, 'inputs')
        for input in inputs:
            metalInputReflectData = findMetalReflectData(metalReflectData['attributes'], input['name'])
            if not metalInputReflectData:
                print(f"ERROR: cannot patch shader reflection data for file: {file}, reflectData: ", metalReflectData['attributes'], 'input name: ',input['name'])
                return None
            input['location'] = int(metalInputReflectData[2]) + numDescriptors

    #update descriptor bindings
    for descriptor in textures:
        metalTextureReflectData = findMetalReflectData(metalReflectData['textures'], descriptor['name'])
        descriptor['set'] = int(metalTextureReflectData[2])
    for descriptor in ubos:
        metalBufferReflectData = findMetalReflectData(metalReflectData['buffers'], descriptor['name'])
        descriptor['set'] = int(metalBufferReflectData[2])
    for descriptor in ssbos:
        metalBufferReflectData = findMetalReflectData(metalReflectData['buffers'], descriptor['name'])
        descriptor['set'] = int(metalBufferReflectData[2])
    for descriptor in images:
        metalTextureReflectData = findMetalReflectData(metalReflectData['textures'], descriptor['name'])
        descriptor['set'] = int(metalTextureReflectData[2])

    return reflectData

def patchShaderReflectionDataHLSL(file, reflectData, ext):
    hlslFile = open(f"{file}", 'r')
    hlslContents = hlslFile.read()
    hlslReflectData = {}

    #parse semantics
    if ext == '.vert':
        inputs = getDictEntry(reflectData, 'inputs')
        for input in inputs:
            hlslReflectData = re.findall(input['name'] + r'\s*:\s*([^;]*);', hlslContents)
            input['semantic'] = hlslReflectData[0]

    #get descriptors
    textures, ubos, ssbos, images = getDictEntries(reflectData, ['textures', 'ubos', 'ssbos', 'images'])
    numDescriptors = len(textures) + len(images) + len(ubos) + len(ssbos)
    descriptors = {}
    for desc in textures: descriptors[desc['set']] = desc
    for desc in ubos: descriptors[desc['set']] = desc
    for desc in ssbos: descriptors[desc['set']] = desc
    for desc in images: descriptors[desc['set']] = desc

    #patch descriptor bindings
    sets = []
    for set in sorted(descriptors):
        desc = descriptors[set]
        while set in sets: set += 1
        desc['set'] = set
        sets.append(set)
        if desc['type'] in ['sampler2D', 'sampler3D', 'samplerCube' ]:
            sets.append(set + 1)

    hlslFile.close()

    return reflectData

def genShaderReflectionMSL(file, outDir):
    result = 0
    filename = os.path.splitext(os.path.basename(file))[0]
    inFileName = f"{outDir}/{filename}.spv.reflect"
    outFileName = f"{outDir}/{filename}.metal.reflect"
    CHECK_TIMESTAMPS(inFileName, outFileName);

    inFile = open(f"{inFileName}", 'r')
    reflectData = json.loads(inFile.read())
    inFile.close()

    ext = os.path.splitext(filename)[1]
    reflectData = patchShaderReflectionDataMSL(file, reflectData, ext)
    if not reflectData:
        print(f"ERROR: cannot generate reflection map for file: {file}")
        return 1
        
    outFile = open(f"{outFileName}", 'w')
    contents = json.dumps(reflectData, sort_keys=True, indent=4, separators=(',', ': '))
    outFile.write(contents)
    outFile.close()

    if result == 0:
        print(f"generated reflection map for file: {file}")
    else:
        print(f"ERROR: cannot generate reflection map for file: {file}")

    return result

def genShaderReflectionHLSL(file, outDir):
    result = 0
    filename = os.path.splitext(os.path.basename(file))[0]
    inFileName = f"{outDir}/{filename}.spv.reflect"
    outFileName = f"{outDir}/{filename}.hlsl.reflect"
    CHECK_TIMESTAMPS(inFileName, outFileName);

    inFile = open(f"{inFileName}", 'r')
    reflectData = json.loads(inFile.read())
    inFile.close()

    ext = os.path.splitext(filename)[1]
    reflectData = patchShaderReflectionDataHLSL(file, reflectData, ext)

    outFile = open(f"{outFileName}", 'w')
    contents = json.dumps(reflectData, sort_keys=True, indent=4, separators=(',', ': '))
    outFile.write(contents)
    outFile.close()

    if result == 0:
        print(f"generated reflection map for file: {file}")
    else:
        print(f"ERROR: cannot generate reflection map for file: {file}")

    return 0

def parseReflectionData(reflectData, ext):
    contents = ''
    if ext == '.vert':
        inputs = getDictEntry(reflectData, 'inputs')
        contents += 'INPUT_ATTRIBUTES {}\n'.format(len(inputs))
        for input in inputs:
            inputName = input['name']
            inputSemantic = ''
            inputNameLower = inputName.lower()
            inputSemantic = 'UNDEFINED'
            if 'semantic' in input: inputSemantic = input['semantic']
            inputTypeMap = {'float': 'VERTEXFORMAT_FLOAT', 'vec2': 'VERTEXFORMAT_FLOAT2', 'vec3': 'VERTEXFORMAT_FLOAT3', 'vec4': 'VERTEXFORMAT_FLOAT4',
                            'ivec2': 'VERTEXFORMAT_INT2', 'ivec3': 'VERTEXFORMAT_INT3', 'ivec4': 'VERTEXFORMAT_INT4',
                            'mat2': 'VERTEXFORMAT_MAT2', 'mat3': 'VERTEXFORMAT_MAT3', 'mat4': 'VERTEXFORMAT_MAT4'}
            inputType = inputTypeMap[input['type']]
            contents += '\t{} {} {} {}\n'.format(inputName, inputSemantic, input['location'], inputType)

    textures, ubos, ssbos, images, types = getDictEntries(reflectData, ['textures', 'ubos','ssbos','images','types'])
    uniformBufferInfos = []
    shaderStorageBufferInfos = []

    def parseMembers(membersData, members, baseOffset = 0, baseName = ''):
        for memberData in membersData:
            typeSizeMap = {'int': 4, 'uint': 4, 'float': 4,
                           'vec2': 8, 'vec3': 12, 'vec4': 16,
                           'ivec2': 8, 'ivec3': 12, 'ivec4': 16,
                           'uvec2': 8, 'uvec3': 12, 'uvec4': 16,
                           'mat2': 16, 'mat3': 36, 'mat4': 64}
            memberType = memberData['type']
            if memberType in typeSizeMap:
                member = memberData.copy()
                member['name'] = baseName + member['name']
                member['size'] = typeSizeMap[memberType]
                member['offset'] += baseOffset
                member['array_count'] = member['array'][0] if 'array' in member else 0
                member['array_stride'] = member['array_stride'] if 'array_stride' in member else 0
                members.append(member)
            elif memberType in types:
                type = types[memberType]
                parseMembers(type['members'], members, baseOffset + memberData['offset'], baseName + memberData['name'] + '.')
            else:
                print(f"ERROR: unrecognized type: {memberType}")

    def parseBuffers(buffers, bufferInfos):
        for buffer in buffers:
            bufferType = types[buffer['type']]
            bufferMembers = []
            parseMembers(bufferType['members'], bufferMembers)
            bufferInfo = {'name':buffer['name'], 'set': buffer['set'], 'binding': buffer['binding'], 'members': bufferMembers}
            bufferInfos.append(bufferInfo)

    parseBuffers(ubos, uniformBufferInfos)
    parseBuffers(ssbos, shaderStorageBufferInfos)

    textureDescriptors = {}; bufferDescriptors = {}
    for texture in textures:
        textureDescriptors[texture['set']] = {'type':texture['type'], 'name':texture['name'], 'set':texture['set'], 'binding':texture['binding']}
    for image in images:
        textureDescriptors[image['set']] = {'type':image['type'], 'name':image['name'], 'set':image['set'], 'binding':image['binding']}
    for ubo in ubos:
        bufferDescriptors[ubo['set']] = {'type':'uniformBuffer', 'name':ubo['name'], 'set':ubo['set'], 'binding':ubo['binding']}
    for ssbo in ssbos:
        bufferDescriptors[ssbo['set']] = {'type':'shaderStorageBuffer', 'name':ssbo['name'], 'set':ssbo['set'], 'binding':ssbo['binding']}
    contents += 'DESCRIPTORS {}\n'.format(len(textureDescriptors) + len(bufferDescriptors))
    descriptorTypeMap = {'sampler2D': 'DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER',
        'sampler3D': 'DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER',
        'samplerCube': 'DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER',
        'image2D': 'DESCRIPTOR_TYPE_STORAGE_IMAGE',
        'uniformBuffer': 'DESCRIPTOR_TYPE_UNIFORM_BUFFER',
        'shaderStorageBuffer': 'DESCRIPTOR_TYPE_STORAGE_BUFFER'}
    for set in sorted(textureDescriptors):
        descriptor = textureDescriptors[set]
        descriptorType = descriptorTypeMap[descriptor['type']]
        contents += '\t{} {} {}\n'.format(descriptor['name'], descriptorType, descriptor['set'])
    for set in sorted(bufferDescriptors):
        descriptor = bufferDescriptors[set]
        descriptorType = descriptorTypeMap[descriptor['type']]
        contents += '\t{} {} {}\n'.format(descriptor['name'], descriptorType, descriptor['set'])
    def processBufferInfos(bufferInfo):
        contents = ''
        memberInfos = bufferInfo['members']
        contents += '{} {} {}\n'.format(bufferInfo['name'], bufferInfo['set'], len(memberInfos))
        for m in memberInfos:
            contents += '{} {} {} {} {}\n'.format(m['name'], m['offset'], m['size'], m['array_count'], m['array_stride'])
        return contents

    contents += 'UNIFORM_BUFFER_INFOS {}\n'.format(len(uniformBufferInfos))
    for bufferInfo in uniformBufferInfos:
        contents += processBufferInfos(bufferInfo)

    contents += 'SHADER_STORAGE_BUFFER_INFOS {}\n'.format(len(shaderStorageBufferInfos))
    for bufferInfo in shaderStorageBufferInfos:
        contents += processBufferInfos(bufferInfo)
    return contents

def generateShaderMapGLSL(file, outDir, outFiles):
    genShaderReflectionGLSL(file, outDir)
    dataPath = os.path.dirname(file)
    filename = os.path.basename(file)
    ext = os.path.splitext(filename)[1]

    inFileName = f"{outDir}/{filename}.spv.reflect"
    outFileName = f"{outDir}/{filename}.spv.map"
    CHECK_TIMESTAMPS(inFileName, outFileName);

    inFile = open(f"{inFileName}", 'r')
    outFile = open(f"{outFileName}", 'w')

    reflectData = json.loads(inFile.read())
    contents = parseReflectionData(reflectData, ext)

    outFile.write(contents)
    outFile.close()
    outFiles.append(outFileName)
    return 0

def generateShaderMapMSL(file, outDir, outFiles):
    genShaderReflectionMSL(file, outDir)
    dataPath = os.path.dirname(file)
    filename = os.path.splitext(os.path.basename(file))[0]
    ext = os.path.splitext(filename)[1]

    inFileName = f"{outDir}/{filename}.metal.reflect"
    outFileName = f"{outDir}/{filename}.metal.map"
    srcTimeStamp = getmtime(inFileName)
    CHECK_TIMESTAMPS(inFileName, outFileName);

    inFile = open(f"{inFileName}", 'r')
    outFile = open(f"{outFileName}", 'w')

    reflectData = json.loads(inFile.read())
    contents = parseReflectionData(reflectData, ext)

    outFile.write(contents)
    outFile.close()
    outFiles.append(outFileName)
    return 0

def generateShaderMapHLSL(file, outDir, outFiles):
    genShaderReflectionHLSL(file, outDir)
    dataPath = os.path.dirname(file)
    filename = os.path.splitext(os.path.basename(file))[0]
    ext = os.path.splitext(filename)[1]

    inFileName = f"{outDir}/{filename}.hlsl.reflect"
    outFileName = f"{outDir}/{filename}.hlsl.map"
    srcTimeStamp = getmtime(inFileName)
    CHECK_TIMESTAMPS(inFileName, outFileName);

    inFile = open(f"{inFileName}", 'r')
    outFile = open(f"{outFileName}", 'w')

    reflectData = json.loads(inFile.read())
    inFile.close()
    contents = parseReflectionData(reflectData, ext)

    outFile.write(contents)
    outFile.close()
    outFiles.append(outFileName)
    return 0
#endif

vector<string> ShaderTools::convertShaders(const vector<string> &files, string outDir, string fmt) {
    vector<string> outFiles;
    for (const string& file: files) convertShader(file, "", outDir, fmt, outFiles);
    return outFiles;
}

vector<string> ShaderTools::compileShaders(const vector<string>& files, const string& defines, string outDir, string fmt) {
    vector<string> outFiles;
    for (const string& file: files) {
        if (fmt == "glsl") compileShaderGLSL(file, defines, outDir, outFiles);
        else if (fmt == "msl") compileShaderMTL(file, defines, outDir, outFiles);
        else if (fmt == "hlsl") compileShaderHLSL(file, defines, outDir, outFiles);
    }
    return outFiles;
}

void ShaderTools::applyPatches(const vector<string> &patchFiles, string outDir) {
    for (const string& patchFile: patchFiles) {
        string filename = FileUtil::splitExt(fs::path(patchFile))[0];
        printf("filename: %s\n", filename.c_str());
        string outFile = fs::path(outDir+"/"+filename);
        if (fs::exists(outFile)) {
            printf("applying patch: {patchFile}");
            string cmdStr = PATCH+" -N -u "+outFile+" -i "+patchFile;
            cmd(cmdStr);
        }
    }
}

vector<string> ShaderTools::generateShaderMaps(const vector<string>& files, string outDir, string fmt) {
    vector<string> outFiles;
    for (const string& file: files) {
        if (fmt == "glsl") generateShaderMapGLSL(file, outDir, outFiles);
        else if (fmt == "msl") generateShaderMapMSL(file, outDir, outFiles);
        else if (fmt == "hlsl") generateShaderMapHLSL(file, outDir, outFiles);
    }
    return outFiles;
}
