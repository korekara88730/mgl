//
//  Camera.cpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "Camera.hpp"

Camera::Camera() {

}

Camera::~Camera() {
	
}


glm::mat4 Camera::getViewMatrix() {
    glm::mat4 result;


	//glm::mat4 CameraMatrix = glm::lookAt(
	//	cameraPosition, // the position of your camera, in world space
	//	cameraTarget,   // where you want to look at, in world space
	//	upVector        // probably glm::vec3(0,1,0), but (0,-1,0) would make you looking upside-down, which can be great too
	//);

	
    return result;
}

glm::mat4 Camera::getProjectionMatrix() {
	glm::mat4 result;
	return result;
}

void Camera::update(float dt) {

}
