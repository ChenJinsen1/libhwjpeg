/*
 * Copyright 2021 Rockchip Electronics Co. LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * author: kevin.chen@rock-chips.com
 */

#ifndef __RK_ENCODER_WRAPER_H__
#define __RK_ENCODER_WRAPER_H__

#include "ExifBuilder.h"
#include "RkExifInfo.h"

typedef struct {
    /* Pointer to thumbnail image, or NULL if not available */
    unsigned char *thumb_data;
    /* Number of bytes in thumbnail image at thumbData */
    int thumb_size;

    unsigned char *header_buf;
    int header_len;

    RkExifInfo *exifInfo;
} RkHeaderData;

/*
 * Parse from RkExifInfo -> ExifData.
 *
 * param[in] exifInfo - populated exif information outside
 * param[out] edata   - EXIF data for type #ExifBuilder
 */
void parse_exif_info(RkExifInfo *exifInfo, ExifData *edata);

/*
 * Release memery allocated at #exif_info_parser
 */
void release_exif_data(ExifData *edata);

/*
 * Generate JPEG exif app1 header.
 *
 * param[in] data     - RkHeaderData
 * param[out] buf     - pointer to buffer pointer containing app1 header data.
 * param[out] len     - pointer to hold the buf number bytes
 */
bool generate_app1_header(RkHeaderData *data, unsigned char **buf, int *len);

#endif  // __RK_ENCODER_WRAPER_H__
