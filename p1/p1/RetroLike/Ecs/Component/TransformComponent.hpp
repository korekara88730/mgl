

#pragma once

#include <glm/glm.hpp>

#include "BaseComponent.hpp"

class TransformComponent : public BaseComponent {
public:
	TransformComponent();
	~TransformComponent();

	glm::vec3& getPos();
	glm::vec3& getScale();
	glm::vec3& getRotation();

	glm::mat4& getModelMatrix();


private:
	
	void computeMatrix();

public:
	glm::vec3	_pos;
	glm::vec3	_scale;
	glm::vec3	_rotation;

	// 整体 model 矩阵  _modelMatrix = _rotationMatrix * _scaleMatrix * _transformMatrix
	glm::mat4	_modelMatrix;

	// 平移矩阵
	glm::mat4	_transformMatrix;
	// 旋转矩阵
	glm::mat4	_scaleMatrix;
	// 缩放矩阵
	glm::mat4	_rotationMatrix;

};

