#include "DrawableComponent.hpp"

DrawableComponent::DrawableComponent() {

}

DrawableComponent::~DrawableComponent() {

}

void DrawableComponent::init(Drawable* pDrawable) {
	_pDrawable = pDrawable;
}

void DrawableComponent::update(float deltaTime) {

}

void DrawableComponent::draw(glm::mat4& modelMatrix, glm::mat4& viewMatrix, glm::mat4 projectionMatrix) {
	if (_pDrawable != nullptr) {
		_pDrawable->draw(modelMatrix,viewMatrix,projectionMatrix);
	}
}
