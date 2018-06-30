//
//  Drawable.hpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#ifndef Drawable_hpp
#define Drawable_hpp

#include <stdio.h>
class Drawable {
public:
    Drawable();
    virtual ~Drawable();
    
    virtual void draw();
    
};
#endif /* Drawable_hpp */
