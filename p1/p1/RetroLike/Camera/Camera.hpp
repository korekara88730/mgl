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

#include "../Ecs/Entity/GameObject.hpp"
#include "../Ecs/Component/TransformComponent.hpp"

class Camera {
    
public:

	Camera();
	~Camera();

    glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();


	void update(float dt);

private:
	glm::vec3	_pos;
	//glm::vec3	_dir;

	/*
		定义 forward 表示相机朝向
		_lookTarget 用 forward 计算出来
		
		好像这样更容易做到  通过键盘鼠标，控制相机

		相机看其他地方，做旋转时，只需要 修改 forward 向量，然后联动 looktarget 做修改 ，这样可能比较简单
		先试试
	*/
	glm::vec3	_lookTarget;
	glm::vec3 _forward;


	glm::vec3	_up;

	float _fovy = 45;
	float _aspect = 1.3f;
	float _zNear = 0.1f;
	float _zFar = 100.0f;


private:
	//GameObject		_transformObject;
};

#endif /* Camera_hpp */
