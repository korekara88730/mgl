#include "InputManager.h"
#include <GLFW/glfw3.h>

InputManager::InputManager() {
    
}

InputManager::~InputManager() {
    
}

InputManager* InputManager::getInstance() {
	static InputManager instance;
	return &instance;
}



static void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    InputManager::getInstance()->onKeyboardEvent(window,key,scancode,action,mods);
}

void InputManager::init(GLFWwindow* pWindow) {
    glfwSetKeyCallback(pWindow,keyboardCallback);
}

// keyboard
void InputManager::onKeyboardEvent(GLFWwindow* window, int key, int scancode, int action, int mods) {
    for(auto listener:_keyboardListeners) {
        switch (action) {
            case GLFW_PRESS:
                listener->onKeyPress(key);
                break;
            case GLFW_RELEASE:
                listener->onKeyRelease(key);
                break;
        }
    }
}

void InputManager::registerKeyboardListener(IKeyboardInputListener* pListener) {
    auto pTarget = std::find(_keyboardListeners.begin(),_keyboardListeners.end(),pListener);
    if(pTarget == _keyboardListeners.end()){
        _keyboardListeners.push_back(pListener);
    }
}

void InputManager::unregisterKeyboardListener(IKeyboardInputListener* pListener) {
    auto pTarget = std::find(_keyboardListeners.begin(),_keyboardListeners.end(),pListener);
    if(pTarget != _keyboardListeners.end()){
        _keyboardListeners.erase(pTarget);
    }
}
