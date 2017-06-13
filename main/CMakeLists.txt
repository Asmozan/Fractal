set(Main_SRCS
    main.cpp
)

add_executable(Fractal
    ${Main_SRCS}
)

# Specify here the libraries this program depends on
target_link_libraries(Fractal
    src
)

install(TARGETS Fractal DESTINATION bin)
