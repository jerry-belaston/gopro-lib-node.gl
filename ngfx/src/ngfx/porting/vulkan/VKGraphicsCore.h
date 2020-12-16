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
#pragma once
#include <vulkan/vulkan.h>

namespace ngfx {

#define VK(s) s = VK_##s
    enum PrimitiveTopology {
        VK(PRIMITIVE_TOPOLOGY_POINT_LIST),
        VK(PRIMITIVE_TOPOLOGY_LINE_LIST),
        VK(PRIMITIVE_TOPOLOGY_LINE_STRIP),
        VK(PRIMITIVE_TOPOLOGY_TRIANGLE_LIST),
        VK(PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP)
    }; 
    enum PolygonMode {
        VK(POLYGON_MODE_FILL),
        VK(POLYGON_MODE_LINE),
        VK(POLYGON_MODE_POINT)
    };
    enum BlendFactor {
        VK(BLEND_FACTOR_ZERO),
        VK(BLEND_FACTOR_ONE),
        VK(BLEND_FACTOR_SRC_COLOR),
        VK(BLEND_FACTOR_ONE_MINUS_SRC_COLOR),
        VK(BLEND_FACTOR_DST_COLOR),
        VK(BLEND_FACTOR_ONE_MINUS_DST_COLOR),
        VK(BLEND_FACTOR_SRC_ALPHA),
        VK(BLEND_FACTOR_ONE_MINUS_SRC_ALPHA),
        VK(BLEND_FACTOR_DST_ALPHA),
        VK(BLEND_FACTOR_ONE_MINUS_DST_ALPHA),
        VK(BLEND_FACTOR_CONSTANT_COLOR),
        VK(BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR),
        VK(BLEND_FACTOR_CONSTANT_ALPHA),
        VK(BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA),
        VK(BLEND_FACTOR_SRC_ALPHA_SATURATE),
    };
    enum BlendOp {
        VK(BLEND_OP_ADD),
        VK(BLEND_OP_SUBTRACT),
        VK(BLEND_OP_REVERSE_SUBTRACT),
        VK(BLEND_OP_MIN),
        VK(BLEND_OP_MAX)
    };
    enum BufferUsageFlagBits {
        VK(BUFFER_USAGE_TRANSFER_SRC_BIT),
        VK(BUFFER_USAGE_TRANSFER_DST_BIT),
        VK(BUFFER_USAGE_UNIFORM_BUFFER_BIT),
        VK(BUFFER_USAGE_STORAGE_BUFFER_BIT),
        VK(BUFFER_USAGE_VERTEX_BUFFER_BIT),
        VK(BUFFER_USAGE_INDEX_BUFFER_BIT)
    };
    enum ColorComponentFlagBits {
        VK(COLOR_COMPONENT_R_BIT),
        VK(COLOR_COMPONENT_G_BIT),
        VK(COLOR_COMPONENT_B_BIT),
        VK(COLOR_COMPONENT_A_BIT)
    };
    enum CommandBufferLevel {
        VK(COMMAND_BUFFER_LEVEL_PRIMARY),
        VK(COMMAND_BUFFER_LEVEL_SECONDARY)
    };
    enum CullModeFlags {
        VK(CULL_MODE_NONE),
        VK(CULL_MODE_FRONT_BIT),
        VK(CULL_MODE_BACK_BIT),
        VK(CULL_MODE_FRONT_AND_BACK)
    };
    enum FenceCreateFlagBits {
        VK(FENCE_CREATE_SIGNALED_BIT),
    };
    enum FrontFace {
        VK(FRONT_FACE_COUNTER_CLOCKWISE),
        VK(FRONT_FACE_CLOCKWISE)
    };
    enum TextureType {
        TEXTURE_TYPE_2D = VK_IMAGE_VIEW_TYPE_2D,
        TEXTURE_TYPE_3D = VK_IMAGE_TYPE_3D,
        TEXTURE_TYPE_CUBE = VK_IMAGE_VIEW_TYPE_CUBE,
        TEXTURE_TYPE_2D_ARRAY = VK_IMAGE_VIEW_TYPE_2D_ARRAY
    };
    enum ImageUsageFlagBits {
        VK(IMAGE_USAGE_TRANSFER_SRC_BIT),
        VK(IMAGE_USAGE_TRANSFER_DST_BIT),
        VK(IMAGE_USAGE_SAMPLED_BIT),
        VK(IMAGE_USAGE_STORAGE_BIT),
        VK(IMAGE_USAGE_COLOR_ATTACHMENT_BIT),
        VK(IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT),
        VK(IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT),
        VK(IMAGE_USAGE_INPUT_ATTACHMENT_BIT),
    };
    enum PipelineStageFlagBits {
        VK(PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT)
    };
    enum ShaderStageFlagBits {
        VK(SHADER_STAGE_VERTEX_BIT),
        VK(SHADER_STAGE_TESSELLATION_CONTROL_BIT),
        VK(SHADER_STAGE_TESSELLATION_EVALUATION_BIT),
        VK(SHADER_STAGE_GEOMETRY_BIT),
        VK(SHADER_STAGE_FRAGMENT_BIT),
        VK(SHADER_STAGE_COMPUTE_BIT),
        VK(SHADER_STAGE_ALL_GRAPHICS),
        VK(SHADER_STAGE_ALL)
    };

#define DEFINE_PIXELFORMATS(s, t0, t1) \
PIXELFORMAT_R##s##_##t0 = VK_FORMAT_R##s##_##t1, \
PIXELFORMAT_RG##s##_##t0 = VK_FORMAT_R##s##G##s##_##t1, \
PIXELFORMAT_RGBA##s##_##t0 = VK_FORMAT_R##s##G##s##B##s##A##s##_##t1

    enum PixelFormat {
        PIXELFORMAT_UNDEFINED = VK_FORMAT_UNDEFINED,
        DEFINE_PIXELFORMATS(8, UNORM, UNORM),
        DEFINE_PIXELFORMATS(16, UINT, UINT),
        DEFINE_PIXELFORMATS(16, SFLOAT, SFLOAT),
        DEFINE_PIXELFORMATS(32, UINT, UINT),
        DEFINE_PIXELFORMATS(32, SFLOAT, SFLOAT),
        PIXELFORMAT_BGRA8_UNORM = VK_FORMAT_B8G8R8A8_UNORM,
        PIXELFORMAT_D16_UNORM = VK_FORMAT_D16_UNORM,
        PIXELFORMAT_D24_UNORM = VK_FORMAT_X8_D24_UNORM_PACK32,
        PIXELFORMAT_D24_UNORM_S8 = VK_FORMAT_D24_UNORM_S8_UINT
    };

    enum IndexFormat {
        INDEXFORMAT_UINT16 = VK_INDEX_TYPE_UINT16,
        INDEXFORMAT_UINT32 = VK_INDEX_TYPE_UINT32
    };

#define DEFINE_VERTEXFORMATS(s, t0, t1) \
VERTEXFORMAT_##t0 = VK_FORMAT_R##s##_##t1, \
VERTEXFORMAT_##t0##2 = VK_FORMAT_R##s##G##s##_##t1, \
VERTEXFORMAT_##t0##3 = VK_FORMAT_R##s##G##s##B##s##_##t1, \
VERTEXFORMAT_##t0##4 = VK_FORMAT_R##s##G##s##B##s##A##s##_##t1

    enum VertexFormat {
        DEFINE_VERTEXFORMATS(32, FLOAT, SFLOAT)
    };

    enum DescriptorType {
        VK(DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER),
        VK(DESCRIPTOR_TYPE_STORAGE_IMAGE),
        VK(DESCRIPTOR_TYPE_UNIFORM_BUFFER),
        VK(DESCRIPTOR_TYPE_STORAGE_BUFFER)
    };
    enum VertexInputRate {
        VK(VERTEX_INPUT_RATE_VERTEX),
        VK(VERTEX_INPUT_RATE_INSTANCE)
    };

    enum FilterMode {
        VK(FILTER_NEAREST),
        VK(FILTER_LINEAR)
    };

    enum ImageLayout {
        VK(IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL),
        VK(IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL),
        VK(IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL),
        VK(IMAGE_LAYOUT_GENERAL)
    };
}