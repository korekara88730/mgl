
#include "TransformComponent.hpp"
#include <glm/ext.hpp>

TransformComponent::TransformComponent() {
	_pos.x = 0,0,0;
	_scale.x = _scale.y = _scale.z = 1;
	_rotation.x  = _rotation.y, _rotation.z = 0;

	computeMatrix();
}

void TransformComponent::computeMatrix() {

	// transform matrix
	//_transformMatrix[0].w = _pos.x;
	//_transformMatrix[1].w = _pos.y;
	//_transformMatrix[2].w = _pos.z;
	//_transformMatrix[3].w = 1;
	_transformMatrix = glm::translate(glm::mat4(), glm::vec3(_pos.x, _pos.y, _pos.z));

	// scale matrix
	//_scaleMatrix[0].x = _scale.x;
	//_scaleMatrix[1].y = _scale.y;
	//_scaleMatrix[2].z = _scale.z;
	//_scaleMatrix[3].w = 1;
	_scaleMatrix = glm::scale(glm::mat4(), glm::vec3(_scale.x, _scale.y, _scale.z));

	// rotation matrix
	// @miao @todo


	_modelMatrix = _rotationMatrix * _scaleMatrix * _transformMatrix;
}

TransformComponent::~TransformComponent() {

}

glm::vec3& TransformComponent::getPos() {
	return _pos;
}

glm::vec3& TransformComponent::getScale() {
	return _scale;
}

glm::vec3& TransformComponent::getRotation() {
	return _rotation;
}

glm::mat4& TransformComponent::getModelMatrix() {
	computeMatrix();
	return _modelMatrix;
}

glm::vec3 TransformComponent::getDirection() {
	glm::vec3 dir;
	// @miao @todo


	return dir;
}

