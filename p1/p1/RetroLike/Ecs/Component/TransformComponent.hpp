

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

	// ���� model ����  _modelMatrix = _rotationMatrix * _scaleMatrix * _transformMatrix
	glm::mat4	_modelMatrix;

	// ƽ�ƾ���
	glm::mat4	_transformMatrix;
	// ��ת����
	glm::mat4	_scaleMatrix;
	// ���ž���
	glm::mat4	_rotationMatrix;

};

