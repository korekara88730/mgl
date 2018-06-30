//
//  RetroGame.cpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "RetroGame.hpp"
#include "ModelComponent.hpp"
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
    
}

void RetroGame::initWorlds() {
    if(_pGameWorld == nullptr){
        _pGameWorld = new GameWorld();
        
    }
}

void RetroGame::startGame() {
    // test objects
    auto obj1 = ObjectManager::getInstance()->createObject();
    obj1->addComponent<ModelComponent>();
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

