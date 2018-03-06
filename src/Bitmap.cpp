#include <fstream>
#include <iostream>

#include "Bitmap.hpp"
#include "BitmapInformation.hpp"
#include "BitmapHeader.hpp"

Bitmap::Bitmap(int width, int height)
    : width_(width), height_(height) , pixelPtr_(new std::uint8_t[width * height * 3]{})
{

}

bool Bitmap::write(std::__cxx11::string fileName)
{
    BitmapInformation bitmapInfo;
    BitmapHeader bitmapHeader;

    bitmapHeader.fileSize = sizeof(BitmapHeader) + sizeof(BitmapInformation) + width_ * height_ * 3;
    bitmapHeader.dataOffset = sizeof(BitmapHeader) + sizeof(BitmapInformation);

    bitmapInfo.width = width_;
    bitmapInfo.height = height_;

    std::ofstream file;

    file.open(fileName, std::ios::out | std::ios::binary);

    if(!file)
    {
        return false;
    }

    file.write((char* )&bitmapHeader, sizeof(bitmapHeader));
    file.write((char* )&bitmapInfo, sizeof(bitmapInfo));
    file.write((char* )pixelPtr_.get(), width_ * height_ *3);

    file.close();


    if(!file)
    {
        return false;
    }

    return true;
}

void Bitmap::setPixel(int xAxis, int yAxis, uint8_t red, uint8_t green, uint8_t blue)
{
    std::uint8_t *pixelPtr = pixelPtr_.get();

    pixelPtr += (yAxis*3) * width_ + (xAxis*3);

    pixelPtr[0] = blue;
    pixelPtr[1] = green;
    pixelPtr[2] = red;

}

Bitmap::~Bitmap(){}

