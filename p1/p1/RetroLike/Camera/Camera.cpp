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
    return result;
}

glm::mat4 Camera::getProjectionMatrix() {
	glm::mat4 result;
	return result;
}

void Camera::update(float dt) {

}
