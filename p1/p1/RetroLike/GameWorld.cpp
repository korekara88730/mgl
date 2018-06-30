//
//  GameWorld.cpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "GameWorld.hpp"
#include "ObjectManager.hpp"
#include "ModelComponent.hpp"

GameWorld::GameWorld() {
    
    
    
}

GameWorld::~GameWorld(){
    
}

void GameWorld::update(float deltaTime) {
    
    
}

void GameWorld::draw() {
    ObjectManager::getInstance()->filterObjsDoFunc<ModelComponent>([](GameObject* obj){
        
        printf("%u\n",obj->id());
        
    });
}
