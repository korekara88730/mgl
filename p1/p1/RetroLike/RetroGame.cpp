//
//  RetroGame.cpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "RetroGame.hpp"
#include "Ecs/Component/ModelComponent.hpp"
#include "ObjectManager.hpp"

RetroGame::RetroGame() {
    
    
}

RetroGame::~RetroGame() {
    if(_pGameWorld != nullptr){
        delete _pGameWorld;
        _pGameWorld = nullptr;
    }
}

void RetroGame::init() {
    initWorlds();
	initInput();
}

void RetroGame::initWorlds() {
    if(_pGameWorld == nullptr){
        _pGameWorld = new GameWorld();
        
    }
}

void RetroGame::initInput() {

}

void RetroGame::startGame() {
    // test objects
	{
		auto obj1 = ObjectManager::getInstance()->createObject();
		obj1->addComponent<ModelComponent>();
		auto transComp = obj1->getComponent<TransformComponent>();
		transComp->setPos(0, 0, 1);
	}
    
	{
		auto obj2 = ObjectManager::getInstance()->createObject();
		obj2->addComponent<ModelComponent>();
		auto transComp = obj2->getComponent<TransformComponent>();
		transComp->setPos(0, 1, 1);
	}
	

	// camera
	if (_pGameWorld != nullptr) {
		auto camera = _pGameWorld->getCamera();
		if (camera != nullptr) {
			
		}
	}
}

void RetroGame::update(float deltaTime) {
    if(_pGameWorld != nullptr ) {
        _pGameWorld->update(deltaTime);
    }
}

void RetroGame::draw() {
    if(_pGameWorld != nullptr){
        _pGameWorld->draw();
    }
}

