#include <iostream>

#include "../src/Bitmap.hpp"

int main()
{
    int width = 800;
    int height = 600;

    Bitmap bitmap(width, height);

    //bitmap.setPixel(width/2, height/2, 255, 255, 255);

    for (int y = 0 ; y < height ; y++)
    {
        for (int x = 0 ; x < width ; x++)
        {
            bitmap.setPixel(x, y, 0, 255, 0);
        }
    }
    bitmap.write("test.bmp");

    std::cout << "Finished" << std::endl;
}
