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
}
