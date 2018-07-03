#include "Winform.h"

#include <iostream>
using namespace std;

#include "common/Shader.hpp"

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
    // depth test
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    // culling
//    glEnable(GL_CULL_FACE);
    
    while (!glfwWindowShouldClose(_pWindow))
    {
        // delta time
        double currentTime = glfwGetTime();
        static double lastTime = glfwGetTime();
        float deltaTime = float(currentTime - lastTime);
        lastTime = currentTime;
        
        // renderer
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
        
        if(_pGame != nullptr) {
            _pGame->update(deltaTime);
            _pGame->draw();
        }
        
        glfwPollEvents();
        glfwSwapBuffers(_pWindow);
    }
}



void Winform::prepareContent() {
	// shader
	p1sh::ShaderManager::getInstance()->initAllShaders();


	// game
    _pGame = new RetroGame();
    _pGame->init();
    _pGame->startGame();
}

void Winform::cleanContent() {
    if(_pGame != nullptr) {
        delete _pGame;
        _pGame = nullptr;
    }
}




