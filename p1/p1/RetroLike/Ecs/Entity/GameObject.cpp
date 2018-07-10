//
//  GameObject.cpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "GameObject.hpp"



GameObject::GameObject(unsigned int id)
:_id(id) {
	
	addComponent<TransformComponent>();
    
}

GameObject::~GameObject() {
    // remove components
    for (auto comp : _components) {
        delete comp;
    }
    _components.clear();
}

