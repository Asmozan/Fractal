#ifndef FRACTAL_ZOOM_HPP
#define FRACTAL_ZOOM_HPP

#include <vector>

struct Zoom
{
public:
    Zoom(int x, int y, double scale) : x(x), y(y), scale(scale)
    {
    };
    double scale{1.0};
    int y{0};
    int x{0};
    
};

#endif //FRACTAL_ZOOM_HPP
