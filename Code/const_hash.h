#pragma once

namespace const_hash {
/*
// CRC32 Table (zlib polynomial)
static constexpr uint32_t crc_table[256] = {
    0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL, 0x076dc419L,
    0x706af48fL, 0xe963a535L, 0x9e6495a3L, 0x0edb8832L, 0x79dcb8a4L,
    0xe0d5e91eL, 0x97d2d988L, 0x09b64c2bL, 0x7eb17cbdL, 0xe7b82d07L,
...
};
template<size_t idx>
constexpr uint32_t crc32(const char * str)
{
    return (crc32<idx-1>(str) >> 8) ^ crc_table[(crc32<idx-1>(str) ^ str[idx]) & 0x000000FF];
}

// This is the stop-recursion function
template<>
constexpr uint32_t crc32<size_t(-1)>(const char * str)
{
    return 0xFFFFFFFF;
}

// This doesn't take into account the nul char
#define COMPILE_TIME_CRC32_STR(x) (crc32<sizeof(x) - 2>(x) ^ 0xFFFFFFFF)

enum TestEnum
{
    CrcVal01 = COMPILE_TIME_CRC32_STR("stack-overflow"),
};
*/
}