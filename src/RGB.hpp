#ifndef FRACTAL_RGB_HPP
#define FRACTAL_RGB_HPP


struct RGB
{
public:
    RGB(int red, int green, int blue);
    
    RGB operator-(const RGB& second);
    
    int _red;
    int _green;
    int _blue;
};


#endif //FRACTAL_RGB_HPP
