#pragma once

#include "../Event/Event.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

class IKeyboardInputListener;
class InputManager {
public:
	~InputManager();
	static InputManager* getInstance();
    
    void init(GLFWwindow* pWindow);
    
    
    void registerKeyboardListener(IKeyboardInputListener* pListener);
    void unregisterKeyboardListener(IKeyboardInputListener* pListener);
    
    // callback
    void onKeyboardEvent(GLFWwindow* window, int key, int scancode, int action, int mods);
    
    
private:
	InputManager();

    
private:
    std::vector<IKeyboardInputListener*> _keyboardListeners;
    
};

class IMouseInputListener {
public:
    virtual void onMouseMove() = 0;
    virtual void onMousePress() = 0;
    virtual void onMouseRelease() = 0;
};

class IKeyboardInputListener {
public:
    virtual void onKeyPress(int key) = 0;
    virtual void onKeyRelease(int key) = 0;
};

