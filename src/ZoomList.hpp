#ifndef FRACTAL_ZOOMLIST_HPP
#define FRACTAL_ZOOMLIST_HPP

#include <vector>
#include <utility>

#include "Zoom.hpp"

class ZoomList
{
public:
    ZoomList(int width, int height);
    
    void add(const Zoom& zoom);
    
    std::pair<double, double> doZoom(int x, int y);

private:
    int _width{0};
    int _height{0};
    double _xCenter{0};
    double _yCenter{0};
    double _scale{1.0};
    
    std::vector<Zoom> _zooms;
};


#endif //FRACTAL_ZOOMLIST_HPP
