#ifndef _CRC32_H_
#define _CRC32_H_

#include <stddef.h>
#include <stdint.h>

uint32_t crc32(const void *buf, size_t size);

#endif