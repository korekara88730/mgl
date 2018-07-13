//
//  Camera.cpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "Camera.hpp"

Camera::Camera() {
	//_pos.x = _pos.y = _pos.z = 0;
	_pos.x = 4.0f;
	_pos.y = 3.0f;
	_pos.z = 3.0f;

	_dir.x = 0.0f;
	_dir.y = 0.0f;
	_dir.z = 0.0f;

	_up.x = 0;
	_up.y = 1;
	_up.z = 0;
}

Camera::~Camera() {
	
}


glm::mat4 Camera::getViewMatrix() {
    glm::mat4 result;
	result = glm::lookAt(_pos,_dir,_up );
    return result;
}

glm::mat4 Camera::getProjectionMatrix() {
	glm::mat4 result;
	result = glm::perspective(glm::radians(_fovy), _aspect, _zNear, _zFar);
	return result;
}

void Camera::update(float dt) {

}
