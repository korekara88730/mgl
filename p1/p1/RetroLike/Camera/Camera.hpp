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
    
public:

	Camera();
	~Camera();

    glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();


	void update(float dt);

private:
	glm::vec3	_pos;
	glm::vec3	_dir;
};

#endif /* Camera_hpp */
