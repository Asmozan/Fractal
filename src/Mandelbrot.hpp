#ifndef FRACTAL_MANDELBROT_HPP
#define FRACTAL_MANDELBROT_HPP

#include <complex>

class Mandelbrot
{
public:
    Mandelbrot();
    
    virtual ~Mandelbrot();
    
    static int getIterations(double x, double y)
    {
        std::complex<double> z = 0;
        std::complex<double> c(x, y);
        
        int iterations = 0;
        
        while (iterations < maxIterations)
        {
            z = z * z + c;
            
            if (std::abs(z) > 2)
            {
                break;
            }
            iterations++;
        }
        
        return iterations;
    }
    
    static const int maxIterations = 1000;
};


#endif //FRACTAL_MANDELBROT_HPP
