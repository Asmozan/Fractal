
#include <iostream>
#include <memory>
#include <ZoomList.hpp>

#include "../src/Mandelbrot.hpp"
#include "FractalMaker.hpp"

int main()
{
    FractalMaker fractalMaker(800, 600);
    
    fractalMaker.useRange(0.0, RGB(0, 0, 255));
    fractalMaker.useRange(0.5, RGB(255, 111, 121));
    fractalMaker.useRange(1.0, RGB(132, 0, 0));
    
    fractalMaker.addZoom(Zoom(295, 202, 0.1));
    
    fractalMaker.run("test.bmp");
    std::cout << "Finished" << std::endl;
}
