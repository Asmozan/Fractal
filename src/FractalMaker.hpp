#ifndef FRACTAL_FRACTALMAKER_HPP
#define FRACTAL_FRACTALMAKER_HPP

#include <string>
#include <memory>
#include "Zoom.hpp"
#include "Mandelbrot.hpp"
#include "Bitmap.hpp"
#include "ZoomList.hpp"
#include "RGB.hpp"

class string;

class FractalMaker
{
public:
    void run(std::string filename);
    
    FractalMaker(int width, int height);
    
    FractalMaker(const Bitmap& bitmap);
    
    void addZoom(const Zoom& zoom);
    
    void useRange(double range, const RGB& rgb);

private:
    
    
    void calculateIteration();
    
    void drawFractal();
    
    void writeBitmap(std::string filename);
    
    void calculateIterations();
    
    void add(Zoom zoom);
    
    void calculateRangesTotals();
    
    int _width;
    int _height;
    int _total;
    Bitmap _bitmap;
    ZoomList _zoomList;
    std::unique_ptr<int[]> _histogram;
    std::unique_ptr<int[]> _fractal;
    
    int getRange(int iterations) const;
    
    std::vector<int> _ranges;
    std::vector<RGB> _colors;
    std::vector<int> _rangesTotals;
    
    bool isFirstRange{false};
};


#endif //FRACTAL_FRACTALMAKER_HPP
