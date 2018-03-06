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
    int width_{0};
    int height_{0};
    double xCenter_{0};
    double yCenter_{0};
    double scale_{1.0};
    
    std::vector<Zoom> zooms_;
};


#endif //FRACTAL_ZOOMLIST_HPP
