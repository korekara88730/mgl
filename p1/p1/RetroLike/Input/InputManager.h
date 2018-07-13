#pragma once

#include "../Event/Event.h"

class InputManager {
	
public:
	~InputManager();
	static InputManager* getInstance();

private:
	InputManager();

};