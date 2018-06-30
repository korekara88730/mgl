//
//  Cube.hpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp

#include <stdio.h>
#include "Drawable.hpp"

class Cube : public Drawable {
    
public:
    Cube(int size);
    virtual ~Cube();
    
    virtual void draw() override;
private:
    int     _size = 1;
};


#endif /* Cube_hpp */
