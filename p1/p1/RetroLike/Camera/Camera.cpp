//
//  Camera.cpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "Camera.hpp"

Camera::Camera() {
	_pos.x = _pos.y = _pos.z = 0;

	// @miao @test
	//_pos.x = 4;
	//_pos.y = 4;
	//_pos.z = -1;


	//_dir.x = 0.0f;
	//_dir.y = 0.0f;
	//_dir.z = 1.0f;

	//_lookTarget.x = 0.0f;
	//_lookTarget.y = 0.0f;
	//_lookTarget.z = 1.0f;
	//
	//_forward = _lookTarget - _pos;
	
	_forward.x = 0;
	_forward.y = 0;
	_forward.z = 1;

	_lookTarget = _pos + _forward;



	_up.x = 0;
	_up.y = 1;
	_up.z = 0;
}

Camera::~Camera() {
	
}


glm::mat4 Camera::getViewMatrix() {
    glm::mat4 result;
	result = glm::lookAt(_pos, _lookTarget,_up );
    return result;
}

glm::mat4 Camera::getProjectionMatrix() {
	glm::mat4 result;
	result = glm::perspective(glm::radians(_fovy), _aspect, _zNear, _zFar);
	return result;
}

void Camera::update(float dt) {

}
