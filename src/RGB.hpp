#ifndef FRACTAL_RGB_HPP
#define FRACTAL_RGB_HPP


struct RGB
{
public:
    RGB(int red, int green, int blue);
    
    RGB operator-(const RGB& second);

    int red;
    int green;
    int blue;
};


#endif //FRACTAL_RGB_HPP
