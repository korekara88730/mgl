//
//  RetroGame.hpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#ifndef RetroGame_hpp
#define RetroGame_hpp

#include <stdio.h>
#include "GameWorld.hpp"

class RetroGame {
    
public:
    
public:
    RetroGame();
    virtual ~RetroGame();
    
    
public:
    void init();
    void startGame();
    
    void update(float deltaTime);
    void draw();
    
private:
    void initWorlds();
	void initInput();
    
private:
    GameWorld*		_pGameWorld = nullptr;
};

#endif /* RetroGame_hpp */
