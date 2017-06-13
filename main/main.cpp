#include <iostream>

#include "../src/Bitmap.hpp"

int main(int argc, char *argv[])
{
    Bitmap bitmap(800, 600);
    bitmap.write("test");

    std::cout << "Finished" << std::endl;
}
