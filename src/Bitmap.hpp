#ifndef BITMAP_H
#define BITMAP_H

#include <cstdint>
#include <memory>
#include <string>

class Bitmap
{
public:
    Bitmap(int width, int height);

    bool write(std::string fileName);
    void setPixel(int xAxis, int yAxis, uint8_t red, uint8_t green, uint8_t blue);

    virtual ~Bitmap();

private:
    int width_{0};
    int height_{0};
    std::unique_ptr<std::uint8_t[]> pixelPtr_{nullptr};
};

#endif // BITMAP_H
