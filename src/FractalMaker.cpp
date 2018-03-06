#include <iostream>
#include <assert.h>
#include "FractalMaker.hpp"

FractalMaker::FractalMaker(int width, int height) : width_(width), height_(height), total_(0),
                                                    histogram_(
                                                            new int[Mandelbrot::maxIterations]{0}),
                                                    fractal_(new int[width_ * height_]{0}),
                                                    bitmap_(width_, height_),
                                                    zoomList_(width_, height_)
{
    void calculateIteration();
    void drawFractal();
    void addZoom(const Zoom& zoom);
    void writeBitmap(std::string filename);
    zoomList_.add(Zoom(width_ / 2, height_ / 2, 4.0 / width_));
}

void FractalMaker::calculateIteration()
{
    for (int y = 0; y < height_; y++)
    {
        for (int x = 0; x < width_; x++)
        {
            std::pair<double, double> coords = zoomList_.doZoom(x, y);
            
            int iterations = Mandelbrot::getIterations(coords.first, coords.second);
            
            fractal_[y * width_ + x] = iterations;
            
            if (iterations != Mandelbrot::maxIterations)
            {
                histogram_[iterations]++;
            }
            histogram_[iterations]++;
        }
    }
    
}

void FractalMaker::drawFractal()
{
    RGB startColor(0, 0, 0);
    RGB endColor(255, 255, 255);
//    RGB diffColor = endColor - startColor;
    for (int y = 0; y < height_; y++)
    {
        for (int x = 0; x < width_; x++)
        {
            int iterations = fractal_[y * width_ + x];
            
            int range = getRange(iterations);
            int rangeTotal = rangesTotals_[range];
            int startRange = ranges_[range];
            
            RGB& startColor = colors_[range];
            RGB& endColor = colors_[range + 1];
            RGB diffColor = endColor - startColor;
            
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;
            
            
            if (iterations != Mandelbrot::maxIterations)
            {
                int totalPixels = 0;
                
                for (int i = startRange; i <= iterations; i++)
                {
                    totalPixels += histogram_[i];
                }
                red = startColor.red + diffColor.red * totalPixels / rangeTotal;
                green = startColor.green + diffColor.green * totalPixels / rangeTotal;
                blue = startColor.blue + diffColor.blue * totalPixels / rangeTotal;
                
            }
            
            bitmap_.setPixel(x, y, red, green, blue);
        }
    }
}

void FractalMaker::addZoom(const Zoom& zoom)
{
    zoomList_.add(zoom);
}

void FractalMaker::writeBitmap(std::string filename)
{
    bitmap_.write(filename);
}

void FractalMaker::calculateIterations()
{
    for (int i = 0; i < Mandelbrot::maxIterations; i++)
    {
        total_ += histogram_[i];
    }
}

void FractalMaker::run(std::string filename)
{
    calculateIteration();
    calculateIterations();
    calculateRangesTotals();
    drawFractal();
    writeBitmap(filename);
}

void FractalMaker::useRange(double range, const RGB& rgb)
{
    ranges_.push_back(range * Mandelbrot::maxIterations);
    colors_.push_back(rgb);
    
    if (isFirstRange)
    {
        rangesTotals_.push_back(0);
    }
    
    isFirstRange = true;
    
    
}

void FractalMaker::calculateRangesTotals()
{
    int index{0};
    
    for (int i = 0; i < Mandelbrot::maxIterations; i++)
    {
        int pixels = histogram_[i];
        
        if (i >= ranges_[index + 1])
        {
            index++;
        }
        rangesTotals_[index] += pixels;
    }
    
    int overallTotal = 0;
    for (int value : rangesTotals_)
    {
        overallTotal += value;
    }
}

int FractalMaker::getRange(int iterations) const // nasty hack, need to refactor this shit
{
    int range = 0;
    
    for (int i = 1; i < ranges_.size(); i++)
    {
        range = i;
        
        if (ranges_[i] > iterations)
        {
            break;
        }
    }
    
    range--;
    
    assert(range > -1);
    assert(range < ranges_.size());
    
    return range;
}


