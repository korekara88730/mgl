//
//  ModelComponent.hpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#ifndef ModelComponent_hpp
#define ModelComponent_hpp

#include <stdio.h>
#include "BaseComponent.hpp"
#include <GL/glew.h>
#include <glm/glm.hpp>

class ModelComponent : public BaseComponent {
public:
    ModelComponent();
    virtual ~ModelComponent();
    

public:
	void update(float deltaTime);
	void draw(glm::mat4& modelMatrix,glm::mat4& viewMatrix,glm::mat4 projectionMatrix);

private:
    void initVertexData();
    void initVertexDataBaseTriangle();
    
public:
    static const int TRIANGLE_VERTEX_SIZE = 9;  // 3 for each vertice,3 vertex.
    GLfloat* _triangle_vertex_buffer_data;
	
	GLuint	_vaoHandle;
	GLuint	_vboVertexPos;

	GLuint	_shaderHandle;


};

#endif /* ModelComponent_hpp */
