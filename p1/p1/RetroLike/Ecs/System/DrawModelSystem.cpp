//
//  DrawModelSystem.cpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "DrawModelSystem.hpp"
#include "../../ObjectManager.hpp"
#include "../Component/ModelComponent.hpp"

DrawModelSystem::DrawModelSystem() {
    
    
}

DrawModelSystem::~DrawModelSystem() {
    
}

void DrawModelSystem::update(float deltaTime) {
	//modelComp->update(deltaTime);
}

void DrawModelSystem::draw() {
	ObjectManager::getInstance()->eachFunc<ModelComponent>([](GameObject* pObject) {
		ModelComponent* modelComp = pObject->getComponent<ModelComponent>();
		modelComp->draw();
	});
}

