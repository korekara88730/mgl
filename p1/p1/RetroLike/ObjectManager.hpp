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
#include "Ecs/Entity/GameObject.hpp"
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
    
    
public:
    
    template<typename CompCls,typename ...Args>
    void filterObjsDoFunc(std::function<void(GameObject* pObject)> func){
        for(auto obj:_objects){
            if(isFitCompCondition<CompCls,Args...>(obj)){
                func(obj);
            }
        }
    }
    
    
private:
    // 外部接口，判断是否包含所有  Component
    template<typename CompCls1,typename CompCls2,typename ...CompCls>
    bool isFitCompCondition(GameObject* pObj){
        return isFitCompCondition<CompCls1>(pObj) && isFitCompCondition<CompCls2,CompCls...>(pObj);
    }
    // 终止函数
    template<typename CmpCls>
    bool isFitCompCondition(GameObject* pObj) {
        return pObj->hasComponent<CmpCls>();
    }
    
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
