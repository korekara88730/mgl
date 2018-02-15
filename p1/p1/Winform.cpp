#include "Winform.h"

#include <iostream>
using namespace std;


#include "VertexObject.hpp"
VertexObject obj;

bool Winform::setup(int width,int height,std::string winName)
{
    if(!glfwInit())
    {
        cout << "glfwInit() error" << endl;
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    _pWindow = glfwCreateWindow(width, height, winName.c_str(), nullptr, nullptr);
    if (_pWindow == nullptr)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(_pWindow);
    if(glewInit() != GLEW_OK)
    {
        cout << "glewInit() error" << endl;
        glfwTerminate();
        return false;
    }
    int genWidth, genHeight;
    glfwGetFramebufferSize(_pWindow, &genWidth, &genHeight);
    glViewport(0, 0, genWidth, genHeight);
    
    
    prepareContent();
    
    return true;
}

void Winform::cleanup()
{
    cleanContent();
    glfwTerminate();
}

void Winform::mainLoop()
{
    while (!glfwWindowShouldClose(_pWindow))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        obj.doDraw();
        
        glfwPollEvents();
        glfwSwapBuffers(_pWindow);
    }
}



void Winform::prepareContent()
{
    obj.prepareData();
}

void Winform::cleanContent()
{
    obj.cleanData();
}




