//
//  DrawModelSystem.hpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#ifndef DrawModelSystem_hpp
#define DrawModelSystem_hpp

#include <stdio.h>
#include "BaseSystem.hpp"
#include "../Component/TransformComponent.hpp"
#include "../Component/ModelComponent.hpp"

class DrawModelSystem : public BaseSystem {
    
public:
    DrawModelSystem();
    virtual ~DrawModelSystem();
    
public:
    virtual void update(float deltaTime) override;
    virtual void draw() override;

private:
	void doDraw(TransformComponent* transComp,ModelComponent* modelComp);
    
};

#endif /* DrawModelSystem_hpp */
