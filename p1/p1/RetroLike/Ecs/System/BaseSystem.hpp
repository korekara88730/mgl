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

class BaseSystem {
public:
    
    BaseSystem();
    virtual ~BaseSystem();
    
public:
    
    virtual void update(float deltaTime) = 0;
    virtual void draw() = 0;
    
};

#endif /* BaseSystem_hpp */
