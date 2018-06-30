//
//  ObjectManager.hpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#ifndef ObjectManager_hpp
#define ObjectManager_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include <vector>

class ObjectManager {
    
public:
    static ObjectManager* getInstance();
    virtual ~ObjectManager();
    
    GameObject* createObject();
    GameObject* getObject(unsigned int id);
    void removeObject(unsigned int id);
    
    void cleanAll();
    
private:
    ObjectManager();
    
private:
    unsigned int getNextIndex() {
        _assignedIndex++;
        return _assignedIndex;
    }
    
private:
    std::vector<GameObject*> _objects;      // 考虑换成 hash
    unsigned int _assignedIndex = 0;
};

#endif /* ObjectManager_hpp */
