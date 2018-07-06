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
	_shaderHandle = p1sh::ShaderManager::getInstance()->getShaderHandle(p1sh::ShaderType::ST_Base);
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

	// vao
	glGenVertexArrays(1, &_vaoHandle);
	glBindVertexArray(_vaoHandle);
	glBindVertexArray(0);

	// vertex data
    _triangle_vertex_buffer_data = new GLfloat[TRIANGLE_VERTEX_SIZE];
    int index = 0;
    // point 1
    _triangle_vertex_buffer_data[index++] = -1.0f;
    _triangle_vertex_buffer_data[index++] = -1.0f;
    _triangle_vertex_buffer_data[index++] =  0.0f;
    // point 2
    _triangle_vertex_buffer_data[index++] =  1.0f;
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


}

void ModelComponent::update(float deltaTime) {

}

void ModelComponent::draw() {


	// mvp 参数
	// 临时都写在这里。具体应该由 camera 来生成 矩阵
	// @temp
	// result
	//float FoV = 45.0;
	//glm::mat4 pMat = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 10000.0f);
	//glm::mat4 vMat = glm::lookAt(
	//	//glm::vec3(0,0,0),           // Camera is here
	//	glm::vec3(0, 0, -1),           // Camera is here
	//	glm::vec3(0,0,0) + glm::vec3(0,0,1), // and looks here : at the same position, plus "direction"
	//	glm::vec3(0,1,0)                  // Head is up (set to 0,-1,0 to look upside-down)
	//	);
	//glm::mat4 modelMatrix = glm::mat4(1.0f);

	//glm::mat4 mvp = pMat * vMat * modelMatrix;


	//GLuint matrixID = glGetUniformLocation(_shaderHandle, "MVP");
	//glUniformMatrix4fv(matrixID, 1,GL_FALSE, &mvp[0][0]);


	//  vertexPosition_modelspace 参数
	// vbo data -> vao
	/*glBindVertexArray(_vaoHandle);
	glBindBuffer(GL_ARRAY_BUFFER, _vboVertexPos);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 9, _triangle_vertex_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);*/


	// predraw
	glBindVertexArray(_vaoHandle);
	glUseProgram(_shaderHandle);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, _vboVertexPos);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 9, _triangle_vertex_buffer_data, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);
	

	// do draw
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// after draw
	glUseProgram(0);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
	
}

