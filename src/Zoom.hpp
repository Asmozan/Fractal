#ifndef FRACTAL_ZOOM_HPP
#define FRACTAL_ZOOM_HPP

#include <vector>


class Zoom
{
public:
    Zoom(int x, int y, double scale) : _x(x), _y(y), _scale(scale)
    {
    };
    double _scale{1.0};
    int _y{0};
    int _x{0};
    
};

#endif //FRACTAL_ZOOM_HPP
