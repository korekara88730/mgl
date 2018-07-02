//
//  GameObject.hpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include <vector>
#include "../Component/BaseComponent.hpp"
#include <cassert>
#include <functional>

using namespace std;

class GameObject {
    
public:
    GameObject(unsigned int id);
    ~GameObject();
    
    unsigned int id() const { return _id; }
    
    template<typename CompCls>
    void addComponent(){
        assert(getComponent<CompCls>() == nullptr);
        CompCls* comp = new CompCls();
        _components.push_back(comp);
    }
    
    template<typename CompCls>
    void removeComponent(){
        for(auto iter = _components.begin();iter != _components.end();++iter) {
            if(dynamic_cast<CompCls*>(*iter) != nullptr){
                _components.erase(iter);
                break;
            }
        }
    }
    
    template<typename CompCls>
    CompCls* getComponent(){
        for (auto comp : _components) {
            if(dynamic_cast<CompCls*>(comp) != nullptr){
                return static_cast<CompCls*>(comp);
            }
        }
        return nullptr;
    }
    
    template<typename CompCls>
    bool hasComponent(){
        for(auto comp:_components){
            if(dynamic_cast<CompCls*>(comp) != nullptr){
                return true;
            }
        }
        return false;
    }
    
private:
    unsigned int _id = -1;
    
    // 这里效率有问题，将来会改成 hash
    std::vector<BaseComponent*>   _components;
};

#endif /* GameObject_hpp */
