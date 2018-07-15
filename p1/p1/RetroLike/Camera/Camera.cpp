//
//  Camera.cpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "Camera.hpp"

Camera::Camera()
{
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

void Camera::changeDirection(const glm::vec3& forward){
    _forward = glm::normalize(forward);
    _lookTarget = _pos + _forward;
}

void Camera::changePosition(const glm::vec3& pos) {
    _pos = pos;
    _lookTarget = _pos + _forward;
}

// GameCamera
GameCamera::GameCamera() {
    InputManager::getInstance()->registerKeyboardListener(this);
}

GameCamera::~GameCamera() {
    InputManager::getInstance()->unregisterKeyboardListener(this);
}

void GameCamera::onKeyPress(int key) {
    _keyPressState[key] = true;
}

void GameCamera::onKeyRelease(int key) {
    _keyPressState[key] = false;
}

bool GameCamera::isKeyPressing(int key){
    auto iter = _keyPressState.find(key);
    if(iter == _keyPressState.end()){
        return false;
    }
    return iter->second;
}

/*
 前 GLFW_KEY_W
 后 GLFW_KEY_S
 向左转 GLFW_KEY_A
 向右转 GLFW_KEY_D
 左平移 GLFW_KEY_Q
 右平移 GLFW_KEY_E
 */
void GameCamera::update(float dt) {
    if(isKeyPressing(GLFW_KEY_W)) {
        moveForward(dt);
    }
    if(isKeyPressing(GLFW_KEY_S)) {
        moveBack(dt);
    }
    if(isKeyPressing(GLFW_KEY_A)) {
        moveLeft(dt);
    }
    if(isKeyPressing(GLFW_KEY_D)) {
        moveRight(dt);
    }
    if(isKeyPressing(GLFW_KEY_UP)) {
        turnUp(dt);
    }
    if(isKeyPressing(GLFW_KEY_DOWN)) {
        turnDown(dt);
    }
    if(isKeyPressing(GLFW_KEY_LEFT)) {
        turnLeft(dt);
    }
    if(isKeyPressing(GLFW_KEY_RIGHT)) {
        turnRight(dt);
    }
    
}

void GameCamera::moveForward(float dt) {
    float offset = _moveSpeed * dt;
    glm::vec3 newPos = _pos + _forward * offset;
    changePosition(newPos);
}

void GameCamera::moveBack(float dt) {
    float offset = -_moveSpeed * dt;
    glm::vec3 newPos = _pos + _forward * offset;
    changePosition(newPos);
}

void GameCamera::moveLeft(float dt) {
    glm::vec3 toward = glm::cross(_forward,_up);
    float offset = -_moveSpeed * dt;
    glm::vec3 newPos = _pos + toward * offset;
    changePosition(newPos);
}

void GameCamera::moveRight(float dt) {
    glm::vec3 toward = glm::cross(_forward,_up) * -1;
    float offset = -_moveSpeed * dt;
    glm::vec3 newPos = _pos + toward * offset;
    changePosition(newPos);
}


void GameCamera::turnUp(float dt) {
    glm::vec3 rightAxis = glm::cross(_forward,_up);
    float deltaAngle = _turnSpeed * dt;
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(),deltaAngle,rightAxis);
    glm::vec4 tmpForward = glm::vec4(_forward.x,_forward.y,_forward.z,1);
    glm::vec4 newForward = rotationMatrix * tmpForward;
    changeDirection(glm::vec3(newForward.x,newForward.y,newForward.z));
}

void GameCamera::turnDown(float dt) {
    glm::vec3 rightAxis = -1 * glm::cross(_forward,_up);
    float deltaAngle = _turnSpeed * dt;
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(),deltaAngle,rightAxis);
    glm::vec4 tmpForward = glm::vec4(_forward.x,_forward.y,_forward.z,1);
    glm::vec4 newForward = rotationMatrix * tmpForward;
    changeDirection(glm::vec3(newForward.x,newForward.y,newForward.z));
}

void GameCamera::turnLeft(float dt) {
    float deltaAngle = _turnSpeed * dt;
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(),deltaAngle,glm::vec3(0,1,0));
    glm::vec4 tmpForward = glm::vec4(_forward.x,_forward.y,_forward.z,1);
    glm::vec4 newForward = rotationMatrix * tmpForward;
    changeDirection(glm::vec3(newForward.x,newForward.y,newForward.z));
}

void GameCamera::turnRight(float dt) {
    float deltaAngle = _turnSpeed * dt * -1;
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(),deltaAngle,glm::vec3(0,1,0));
    glm::vec4 tmpForward = glm::vec4(_forward.x,_forward.y,_forward.z,1);
    glm::vec4 newForward = rotationMatrix * tmpForward;
    changeDirection(glm::vec3(newForward.x,newForward.y,newForward.z));
}

