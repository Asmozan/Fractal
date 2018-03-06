#include "../src/ZoomList.hpp"

ZoomList::ZoomList(int width, int height) : width_(width), height_(height)
{

}

void ZoomList::add(const Zoom& zoom)
{
    zooms_.push_back(zoom);
    xCenter_ += (zoom.x - width_ / 2) * scale_;
    yCenter_ += (zoom.y - height_ / 2) * scale_;
    
    scale_ *= zoom.scale;
}

std::pair<double, double> ZoomList::doZoom(int x, int y)
{
    double xFractal = (x - width_ / 2) * scale_ + xCenter_;
    double yFractal = -(y - height_ / 2) * scale_ + yCenter_;
    
    return std::pair<double, double>(xFractal, yFractal);
}