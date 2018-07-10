

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

public:
	glm::vec3	_pos;
	glm::vec3	_scale;
	glm::vec3	_rotation;


	glm::mat4	_modelMatrix;
};

