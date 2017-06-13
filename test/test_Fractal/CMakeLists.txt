file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(test_Fractal ${SRCS})

TARGET_LINK_LIBRARIES( test_Fractal
    src
    libgtest
)

add_test(NAME  test_Fractal
         COMMAND  test_Fractal)
