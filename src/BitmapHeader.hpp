#ifndef BITMAPEADER_HPP
#define BITMAPEADER_HPP

#include <cstdint>

#pragma pack(2)

struct BitmapHeader
{
public:
    char header[2]{'B', 'M'};
    std::int32_t fileSize;
    std::int32_t reserved{0};
    std::int32_t dataOffset;
};

#endif // BITMAPEADER_HPP
