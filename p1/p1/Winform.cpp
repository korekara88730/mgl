#include "Winform.h"

#include <iostream>
using namespace std;


#include "VertexObject.hpp"


VertexObject obj;


Winform::Winform()
:_viewportW(0)
,_viewportH(0)
{
    
    
}

Winform::~Winform()
{
    
}

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

    glfwGetFramebufferSize(_pWindow, &_viewportW, &_viewportH);
    glViewport(0, 0, _viewportW, _viewportH);
    
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
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    
    
    
    // Ensure we can capture the escape key being pressed below
//    glfwSetInputMode(_pWindow, GLFW_STICKY_KEYS, GL_TRUE);
    // Hide the mouse and enable unlimited mouvement
    glfwSetInputMode(_pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    while (!glfwWindowShouldClose(_pWindow))
    {
        // delta time
        double currentTime = glfwGetTime();
        static double lastTime = glfwGetTime();
        float deltaTime = float(currentTime - lastTime);
        lastTime = currentTime;

        // update
        _control.computeMatricesFromInputs(_pWindow,deltaTime);
        
        // renderer
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
        
        
        glm::mat4 viewMatrix = _control.getViewMatrix();
        glm::mat4 projectionMatrix = _control.getProjectionMatrix();
        obj.doDraw(_viewportW,_viewportH,viewMatrix,projectionMatrix);
        
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




