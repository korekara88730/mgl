//
//  BaseSystem.hpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#ifndef BaseSystem_hpp
#define BaseSystem_hpp

#include <stdio.h>

class GameWorld;
class BaseSystem {
public:
    
    BaseSystem(GameWorld* pWorld);
    virtual ~BaseSystem();
    
public:
    
    virtual void update(float deltaTime) = 0;
    virtual void draw() = 0;


public:
	GameWorld* getWorld() { return _pWorld; }

private:
	GameWorld*	_pWorld = nullptr;
};

#endif /* BaseSystem_hpp */
