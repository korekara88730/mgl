//
//  DrawModelSystem.cpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "DrawModelSystem.hpp"
#include "../../ObjectManager.hpp"
#include "../../GameWorld.hpp"

DrawModelSystem::DrawModelSystem(GameWorld* pWorld):BaseSystem(pWorld) {

}

DrawModelSystem::~DrawModelSystem() {
    
}

void DrawModelSystem::update(float deltaTime) {
	//modelComp->update(deltaTime);
}

void DrawModelSystem::draw() {
	ObjectManager::getInstance()->eachFunc<TransformComponent,ModelComponent>([&](GameObject* pObject) {
		doDraw(pObject->getComponent<TransformComponent>(), pObject->getComponent<ModelComponent>());
	});
	ObjectManager::getInstance()->eachFunc<TransformComponent, DrawableComponent>([&](GameObject* pObject) {
		doDraw(pObject->getComponent<TransformComponent>(), pObject->getComponent<DrawableComponent>());
	});
}

void DrawModelSystem::doDraw(TransformComponent* transComp,ModelComponent* modelComp) {
	glm::mat4 viewMatrix = getWorld()->getCamera()->getViewMatrix();
	glm::mat4 projectionMatrix = getWorld()->getCamera()->getProjectionMatrix();
	modelComp->draw(transComp->getModelMatrix(),viewMatrix,projectionMatrix);
}

void DrawModelSystem::doDraw(TransformComponent* transComp, DrawableComponent* drawableComp) {
	glm::mat4 viewMatrix = getWorld()->getCamera()->getViewMatrix();
	glm::mat4 projectionMatrix = getWorld()->getCamera()->getProjectionMatrix();
	drawableComp->draw(transComp->getModelMatrix(), viewMatrix, projectionMatrix);
}
