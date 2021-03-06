//
// Copyright (c) 2017. See AUTHORS file.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef PIXL_PIXL_H
#define PIXL_PIXL_H

#ifdef __cplusplus
#include "types.h"
#include "errors.h"
#include "image.h"
#include "io.h"
#endif

// ----------------------------------------------------------------------------
// 					C API BELOW (implementation in c_api.cc)
// ----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

static const int PIXL_ORIENTATION_VERTICAL = 0;
static const int PIXL_ORIENTATION_HORIZONTAL = 1;

static const int PIXL_RESIZE_METHOD_NEAREST = 0;
static const int PIXL_RESIZE_METHOD_BILINEAR = 1;

struct PixlImage {
    unsigned int width;
    unsigned int height;
    void* __handle;
};
typedef struct PixlImage PixlImage;

PixlImage* pixl_load_image(const char* path);
void pixl_destroy_image(PixlImage* image);
void pixl_save_image(PixlImage* image, const char* path, int quality);

void pixl_resize(PixlImage* image, unsigned int width, unsigned int height, int method);
void pixl_flip(PixlImage* image, int orientation);
void pixl_grayscale(PixlImage* image);
void pixl_invert(PixlImage* image);
void pixl_convolution(PixlImage* image, float kernel[9], float scale);

#ifdef __cplusplus
}
#endif
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

#endif