#include <iostream>
#include <assert.h>
#include "FractalMaker.hpp"

FractalMaker::FractalMaker(int width, int height) : _width(width), _height(height), _total(0),
                                                    _histogram(
                                                            new int[Mandelbrot::maxIterations]{0}),
                                                    _fractal(new int[_width * _height]{0}),
                                                    _bitmap(_width, _height),
                                                    _zoomList(_width, _height)
{
    void calculateIteration();
    void drawFractal();
    void addZoom(const Zoom& zoom);
    void writeBitmap(std::string filename);
    _zoomList.add(Zoom(_width / 2, _height / 2, 4.0 / _width));
}

void FractalMaker::calculateIteration()
{
    for (int y = 0; y < _height; y++)
    {
        for (int x = 0; x < _width; x++)
        {
            std::pair<double, double> coords = _zoomList.doZoom(x, y);
            
            int iterations = Mandelbrot::getIterations(coords.first, coords.second);
            
            _fractal[y * _width + x] = iterations;
            
            if (iterations != Mandelbrot::maxIterations)
            {
                _histogram[iterations]++;
            }
            
            _histogram[iterations]++;
        }
    }
    
}

void FractalMaker::drawFractal()
{
    RGB startColor(0, 0, 0);
    RGB endColor(255, 255, 255);
//    RGB diffColor = endColor - startColor;
    for (int y = 0; y < _height; y++)
    {
        for (int x = 0; x < _width; x++)
        {
            int iterations = _fractal[y * _width + x];
            
            int range = getRange(iterations);
            int rangeTotal = _rangesTotals[range];
            int startRange = _ranges[range];
            
            RGB& startColor = _colors[range];
            RGB& endColor = _colors[range + 1];
            RGB diffColor = endColor - startColor;
            
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;
            
            
            if (iterations != Mandelbrot::maxIterations)
            {
                int totalPixels = 0;
                
                for (int i = startRange; i <= iterations; i++)
                {
                    totalPixels += _histogram[i];
                }
                red = startColor._red + diffColor._red * totalPixels / rangeTotal;
                green = startColor._green + diffColor._green * totalPixels / rangeTotal;
                blue = startColor._blue + diffColor._blue * totalPixels / rangeTotal;
                
            }
            
            _bitmap.setPixel(x, y, red, green, blue);
        }
    }
}

void FractalMaker::addZoom(const Zoom& zoom)
{
    _zoomList.add(zoom);
}

void FractalMaker::writeBitmap(std::string filename)
{
    _bitmap.write(filename);
}

void FractalMaker::calculateIterations()
{
    for (int i = 0; i < Mandelbrot::maxIterations; i++)
    {
        _total += _histogram[i];
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
    _ranges.push_back(range * Mandelbrot::maxIterations);
    _colors.push_back(rgb);
    
    if (isFirstRange)
    {
        _rangesTotals.push_back(0);
    }
    
    isFirstRange = true;
    
    
}

void FractalMaker::calculateRangesTotals()
{
    int index{0};
    
    for (int i = 0; i < Mandelbrot::maxIterations; i++)
    {
        int pixels = _histogram[i];
        
        if (i >= _ranges[index + 1])
        {
            index++;
        }
        _rangesTotals[index] += pixels;
    }
    
    int overallTotal = 0;
    for (int value : _rangesTotals)
    {
        overallTotal += value;
    }
}

int FractalMaker::getRange(int iterations) const // nasty hack, need to refactor this shit
{
    int range = 0;
    
    for (int i = 1; i < _ranges.size(); i++)
    {
        range = i;
        
        if (_ranges[i] > iterations)
        {
            break;
        }
    }
    
    range--;
    
    assert(range > -1);
    assert(range < _ranges.size());
    
    return range;
}


