#ifndef __MPI_DEBUG_H__
#define __MPI_DEBUG_H__

#include <stdio.h>

#define DEBUG_TIMING        0x00000001
#define DEBUG_RECORD_IN     0x00000002
#define DEBUG_RECORD_OUT    0x00000004

uint32_t get_env_u32(const char* name, uint32_t *value, uint32_t default_value);

#endif  // __MPI_DEBUG_H__
