/*
 * Copyright 2020 GoPro Inc.
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

#ifndef SWAPCHAIN_VK_H
#define SWAPCHAIN_VK_H

#include "nodegl/core/swapchain.h"
#include "nodegl/porting/vk/vkcontext.h"

int ngli_swapchain_vk_create(struct gctx *s);
void ngli_swapchain_vk_destroy(struct gctx *s);
int ngli_swapchain_vk_acquire_image(struct gctx *s, uint32_t *image_index);
int ngli_swapchain_vk_swap_buffers(struct gctx *s);
typedef int (*swapchain_vk_reset_callback)(struct gctx *gctx, struct vkcontext *vk);
void ngli_swapchain_vk_set_reset_callback(swapchain_vk_reset_callback cb);
#endif
