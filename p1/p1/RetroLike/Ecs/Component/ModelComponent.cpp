//
//  ModelComponent.cpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "ModelComponent.hpp"
#include "../../../common/Shader.hpp"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

ModelComponent::ModelComponent()
:_triangle_vertex_buffer_data(nullptr)
,_vaoHandle(0)
,_vboVertexPos(0)
, _shaderHandle(0)
{
	//_shaderHandle = p1sh::ShaderManager::getInstance()->getShaderHandle(p1sh::ShaderType::ST_Base);
	_shaderHandle = p1sh::ShaderManager::getInstance()->getShaderHandle(p1sh::ShaderType::ST_MVP);
	initVertexData();
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

	const static float factor = 1.0f;

	// vertex data
    _triangle_vertex_buffer_data = new GLfloat[TRIANGLE_VERTEX_SIZE];
    int index = 0;
    // point 1
    _triangle_vertex_buffer_data[index++] = -1.0f * factor;
    _triangle_vertex_buffer_data[index++] = -1.0f * factor;
    _triangle_vertex_buffer_data[index++] =  0.0f * factor;
    // point 2
    _triangle_vertex_buffer_data[index++] =  1.0f * factor;
    _triangle_vertex_buffer_data[index++] = -1.0f * factor;
    _triangle_vertex_buffer_data[index++] =  0.0f * factor;
    // point 3
    _triangle_vertex_buffer_data[index++] =  0.0f * factor;
    _triangle_vertex_buffer_data[index++] =  1.0f * factor;
    _triangle_vertex_buffer_data[index++] =  0.0f * factor;

	// vbo
	int dataCnt = index;
	glGenBuffers(1, &_vboVertexPos);
	glBindBuffer(GL_ARRAY_BUFFER, _vboVertexPos);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * dataCnt, _triangle_vertex_buffer_data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// vao
	glGenVertexArrays(1, &_vaoHandle);


	//// VBO DATA TO VAO
	//glBindVertexArray(_vaoHandle);
	//glBindBuffer(GL_ARRAY_BUFFER, _vboVertexPos);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);


}

void ModelComponent::update(float deltaTime) {

}

void ModelComponent::draw(glm::mat4& modelMatrix, glm::mat4& viewMatrix, glm::mat4 projectionMatrix) {


	// predraw
	glBindVertexArray(_vaoHandle);
	glUseProgram(_shaderHandle);
	glEnableVertexAttribArray(0);


	// uniform
	glm::mat4 mvp = projectionMatrix * viewMatrix * modelMatrix;
	GLuint matrixID = glGetUniformLocation(_shaderHandle, "MVP");
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &mvp[0][0]);


	// pass vbo data -> vao
	glBindBuffer(GL_ARRAY_BUFFER, _vboVertexPos);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);



	// do draw
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// after draw
	glUseProgram(0);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
	
}

