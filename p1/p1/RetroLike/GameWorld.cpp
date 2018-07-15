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

	_pMainCamera = new GameCamera();
}

GameWorld::~GameWorld(){
	// remove all systems
    for(auto sys:_allSys){
		delete sys;
	}
	_allSys.clear();

	// remove camera
	if (_pMainCamera != nullptr) {
		delete _pMainCamera;
		_pMainCamera = nullptr;
	}
}

void GameWorld::update(float deltaTime) {
    // update all system
	for (auto sys : _allSys) {
		sys->update(deltaTime);
	}
    
    // @miao @temp
    //  临时只更新 camera 考虑放到一个新的 system 里面
    if(_pMainCamera) {
        _pMainCamera->update(deltaTime);
    }
    
}

void GameWorld::draw() {
	for (auto sys : _allSys) {
		sys->draw();
	}
}
