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
    
    int width_;
    int height_;
    int total_;
    Bitmap bitmap_;
    ZoomList zoomList_;
    std::unique_ptr<int[]> histogram_;
    std::unique_ptr<int[]> fractal_;
    
    int getRange(int iterations) const;
    
    std::vector<int> ranges_;
    std::vector<RGB> colors_;
    std::vector<int> rangesTotals_;
    
    bool isFirstRange{false};
};


#endif //FRACTAL_FRACTALMAKER_HPP
