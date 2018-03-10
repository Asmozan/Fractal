set(src_SRCS
    Bitmap.cpp
    BitmapInformation.hpp
    BitmapHeader.hpp
        RGB.hpp
        Mandelbrot.hpp
        Zoom.hpp
        ZoomList.hpp
        ZoomList.cpp


        FractalMaker.cpp FractalMaker.hpp RGB.cpp RGB.hpp)

# Declare the library
add_library(src STATIC
    ${src_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(src PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
