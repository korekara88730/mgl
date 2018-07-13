#include "InputManager.h"

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

InputManager* InputManager::getInstance() {
	static InputManager instance;
	return &instance;
}
