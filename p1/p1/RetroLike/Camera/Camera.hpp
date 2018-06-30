//
//  Camera.hpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

class Camera {
    
private:
    glm::mat4 getViewMatrix();
};

#endif /* Camera_hpp */
