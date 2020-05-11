#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>

#include "mpp_err.h"
#include "mpp_frame.h"
#include "mpp_packet.h"

void dump_mpp_frame_to_file(MppFrame frame, FILE *fp);
void dump_mpp_packet_to_file(MppPacket packet, FILE *fp);
void dump_data_to_file(uint8_t *data, int size, FILE *fp);

MPP_RET get_file_ptr(const char *file_name, char **buf, size_t *size);
MPP_RET dump_ptr_to_file(char *buf, size_t size, const char *output_file);

MPP_RET crop_yuv_image(uint8_t *src, uint8_t *dst, int src_width, int src_height,
                       int src_wstride, int src_hstride,
                       int dst_width, int dst_height);

MPP_RET read_yuv_image(uint8_t *dst, uint8_t *src, int width, int height,
                       int hor_stride, int ver_stride,
                       MppFrameFormat fmt);
MPP_RET fill_yuv_image(uint8_t *buf, int width, int height,
                       int hor_stride, int ver_stride, MppFrameFormat fmt,
                       int frame_count);

int is_valid_dma_fd(int fd);

#endif //__UTILS_H__
