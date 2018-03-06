#include "RGB.hpp"

RGB::RGB(int red, int green, int blue) : red(red), green(green), blue(blue)
{
}

RGB RGB::operator-(const RGB& second)
{
    return RGB(this->red - second.red, this->green - second.green, this->blue - second.blue);
}
