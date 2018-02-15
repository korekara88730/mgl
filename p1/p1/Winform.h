#ifndef Winform_hpp
#define Winform_hpp

#include <stdio.h>

//#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


class Winform{
public:
    bool setup(int width,int height,std::string winName);
    void cleanup();
    void mainLoop();
    
private:
    GLFWwindow* _pWindow;
};

#endif /* Winform_hpp */
