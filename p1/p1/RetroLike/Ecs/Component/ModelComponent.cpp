//
//  ModelComponent.cpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "ModelComponent.hpp"

ModelComponent::ModelComponent()
:_triangle_vertex_buffer_data(nullptr)
,_vaoHandle(0)
,_vboVertexPos(0)
{
    
    
}

ModelComponent::~ModelComponent() {
    if(_triangle_vertex_buffer_data != nullptr) {
        delete[] _triangle_vertex_buffer_data;
        _triangle_vertex_buffer_data = nullptr;
    }
}

void ModelComponent::initVertexData() {
    initVertexDataBaseTriangle();
}

void ModelComponent::initVertexDataBaseTriangle() {
    _triangle_vertex_buffer_data = new GLfloat[TRIANGLE_VERTEX_SIZE];
    int index = 0;
    // point 1
    _triangle_vertex_buffer_data[index++] = -1.0f;
    _triangle_vertex_buffer_data[index++] = -1.0f;
    _triangle_vertex_buffer_data[index++] =  0.0f;
    // point 2
    _triangle_vertex_buffer_data[index++] = -1.0f;
    _triangle_vertex_buffer_data[index++] = -1.0f;
    _triangle_vertex_buffer_data[index++] =  0.0f;
    // point 3
    _triangle_vertex_buffer_data[index++] =  0.0f;
    _triangle_vertex_buffer_data[index++] =  1.0f;
    _triangle_vertex_buffer_data[index++] =  0.0f;

	// vbo
	int dataCnt = index;
	glGenBuffers(1, &_vboVertexPos);
	glBindBuffer(GL_ARRAY_BUFFER, _vboVertexPos);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * dataCnt, _triangle_vertex_buffer_data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// vao
	glGenVertexArrays(1, &_vaoHandle);
}
