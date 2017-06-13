#include <fstream>
#include <iostream>

#include "Bitmap.hpp"
#include "BitmapInformation.hpp"
#include "BitmapHeader.hpp"

Bitmap::Bitmap(int width, int height)
    : _width(width), _height(height) , _pixelPtr(new std::uint8_t[width * height * 3]{})
{

}

bool Bitmap::write(std::__cxx11::string fileName)
{
    BitmapInformation bitmapInfo;
    BitmapHeader bitmapHeader;

    bitmapHeader.fileSize = sizeof(BitmapHeader) + sizeof(BitmapInformation) + _width * _height * 3;
    bitmapHeader.dataOffset = sizeof(BitmapHeader) + sizeof(BitmapInformation);

    bitmapInfo.width = _width;
    bitmapInfo.height = _height;

    std::ofstream file;

    file.open(fileName, std::ios::out | std::ios::binary);

    if(!file)
    {
        return false;
    }

    file.write((char* )&bitmapHeader, sizeof(bitmapHeader));
    file.write((char* )&bitmapInfo, sizeof(bitmapInfo));
    file.write((char* )_pixelPtr.get(), _width * _height *3);

    file.close();


    if(!file)
    {
        return false;
    }

    return true;
}

void Bitmap::setPixel(int xAxis, int yAxis, uint8_t red, uint8_t green, uint8_t blue)
{

}

Bitmap::~Bitmap(){}

