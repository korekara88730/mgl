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
    
    
}

GameObject::~GameObject() {
    // remove components
    for (auto comp : _components) {
        delete comp;
    }
    _components.clear();
}


//template<typename CompCls>
//void GameObject::addComponent() {
//    assert(getComponent<CompCls>() == nullptr);
//    CompCls* comp = new CompCls();
//    _components.push_back(comp);
//}
//
//template<typename CompCls>
//void GameObject::removeComponent() {
//    for(auto iter = _components.begin();iter != _components.end();++iter) {
//        if(dynamic_cast<CompCls*>(*iter) != nullptr){
//            _components.erase(iter);
//            break;
//        }
//    }
//}
//
//template<typename CompCls>
//CompCls* GameObject::getComponent() {
//    for (auto comp : _components) {
//        if(dynamic_cast<CompCls*>(comp) != nullptr){
//            return comp;
//        }
//    }
//    return nullptr;
//}

