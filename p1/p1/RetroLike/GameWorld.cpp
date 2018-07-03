//
//  GameWorld.cpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "GameWorld.hpp"
#include "ObjectManager.hpp"
//#include "Ecs/Component/ModelComponent.hpp"
#include "Ecs/System/DrawModelSystem.hpp"


GameWorld::GameWorld() {
	registerSystem<DrawModelSystem>();
}

GameWorld::~GameWorld(){
	// remove all systems
    for(auto sys:_allSys){
		delete sys;
	}
	_allSys.clear();
}

void GameWorld::update(float deltaTime) {
	for (auto sys : _allSys) {
		sys->update(deltaTime);
	}
}

void GameWorld::draw() {
	for (auto sys : _allSys) {
		sys->draw();
	}
}
