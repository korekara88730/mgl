//
//  GameWorld.hpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#ifndef GameWorld_hpp
#define GameWorld_hpp

#include <vector>
using namespace std;

#include <stdio.h>
#include "Drawable.hpp"

class GameWorld {
    
public:
    GameWorld();
    virtual ~GameWorld();
    
    
    void update(float deltaTime);
    void draw();
    
private:
    
    vector<Drawable*> _allDrawable;
};

#endif /* GameWorld_hpp */
