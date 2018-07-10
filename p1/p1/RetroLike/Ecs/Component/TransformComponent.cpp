
#include "TransformComponent.hpp"

TransformComponent::TransformComponent() {
	_pos.x = 0,0,0;
	_scale.x = _scale.y = _scale.z = 1;
	_rotation.x  = _rotation.y, _rotation.z = 0;

	//_modelMatrix;


	printf("123213");
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
	
	// 平移
	_modelMatrix[0].w = _pos.x;
	_modelMatrix[1].w = _pos.y;
	_modelMatrix[2].w = _pos.z;


	// 缩放
	_modelMatrix[0].x = _scale.x;
	_modelMatrix[1].y = _scale.y;
	_modelMatrix[2].z = _scale.z;

	// 旋转
	// @miao 
	// 临时不考虑旋转 。。。 @todo

	return _modelMatrix;
}
