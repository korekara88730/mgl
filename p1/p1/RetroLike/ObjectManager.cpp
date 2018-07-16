//
//  ObjectManager.cpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "ObjectManager.hpp"

ObjectManager::ObjectManager() {
    
    
}

ObjectManager::~ObjectManager() {
	cleanAll();
}

ObjectManager* ObjectManager::getInstance() {
    static ObjectManager instance;
    return &instance;
}

GameObject* ObjectManager::createObject(){
    unsigned int objId = getNextIndex();
    GameObject* pObject = new GameObject(objId);
    _objects.push_back(pObject);
    return pObject;
}

GameObject* ObjectManager::getObject(unsigned int id) {
    
    return nullptr;
}

void ObjectManager::removeObject(unsigned int id) {
    for(auto iter = _objects.begin();iter != _objects.end();++iter){
        if((*iter)->id() == id){
            delete (*iter);
            _objects.erase(iter);
            break;
        }
    }
}

void ObjectManager::cleanAll() {
    for(auto iter = _objects.begin();iter != _objects.end();++iter){
        delete (*iter);
    }
    _objects.clear();
}


