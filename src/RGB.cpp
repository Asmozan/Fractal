#include "RGB.hpp"

RGB::RGB(int red, int green, int blue) : _red(red), _green(green), _blue(blue)
{
}

RGB RGB::operator-(const RGB& second)
{
    return RGB(this->_red - second._red, this->_green - second._green, this->_blue - second._blue);
}
