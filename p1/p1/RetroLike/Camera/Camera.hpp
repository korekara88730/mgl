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
	glm::vec3	_up;

	/*
	
		GLM_FUNC_QUALIFIER tmat4x4<T, defaultp> perspective
	(
		T fovy,
		T aspect,
		T zNear,
		T zFar
	)
	*/
	float _fovy = 45;
	float _aspect = 1.3f;
	float _zNear = 0.1f;
	float _zFar = 100.0f;
	
};

#endif /* Camera_hpp */
