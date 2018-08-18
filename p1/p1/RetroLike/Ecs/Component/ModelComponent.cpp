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
	_shaderHandle = p1sh::ShaderManager::getInstance()->getShaderHandle(p1sh::ShaderType::ST_MVP);
}

ModelComponent::~ModelComponent() {
    if(_triangle_vertex_buffer_data != nullptr) {
        delete[] _triangle_vertex_buffer_data;
        _triangle_vertex_buffer_data = nullptr;
    }
	if (_cube_vertex_buffer_data != nullptr) {
		delete[] _cube_vertex_buffer_data;
		_cube_vertex_buffer_data = nullptr;
	}
	if (_rect_vertex_buffer_data != nullptr) {
		delete[] _rect_vertex_buffer_data;
		_rect_vertex_buffer_data = nullptr;
	}
	if (_vboVertexPos) {
		glDeleteBuffers(1, &_vboVertexPos);
	}
	if (_vaoHandle) {
		glDeleteVertexArrays(1, &_vaoHandle);
	}
}

void ModelComponent::init(EModelType modelType) {
	if (hasInit()) {
		return;
	}
	_modelType = modelType;
	switch (_modelType) {
	case EModelType::MT_Triangle:
		initVertexDataBaseTriangle();
		break;
	case EModelType::MT_Cube:
		initVertexDataCube();
		break;
	case EModelType::MT_Rectangle:
		initVertexDataRectangle();
		break;
	default:
//        assert(false,"Invalid model type!");
        assert(false);
		break;
	}
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

	_verticeCnt = 3;

	delete[] _triangle_vertex_buffer_data;
	_triangle_vertex_buffer_data = nullptr;
}

void ModelComponent::initVertexDataCube() {

}

void ModelComponent::initVertexDataRectangle() {
	const static float factor = 1.0f;

	// vertex data
	_rect_vertex_buffer_data = new GLfloat[RECTANGLE_VERTEX_SIZE];
	int index = 0;

	// triangle 1
	// point 1
	_rect_vertex_buffer_data[index++] = -0.5f * factor;
	_rect_vertex_buffer_data[index++] = -0.5f * factor;
	_rect_vertex_buffer_data[index++] = 0.0f * factor;
	// point 2
	_rect_vertex_buffer_data[index++] = 0.5f * factor;
	_rect_vertex_buffer_data[index++] = 0.5f * factor;
	_rect_vertex_buffer_data[index++] = 0.0f * factor;
	// point 3
	_rect_vertex_buffer_data[index++] = -0.5f * factor;
	_rect_vertex_buffer_data[index++] = 0.5f * factor;
	_rect_vertex_buffer_data[index++] = 0.0f * factor;

	// triangle 2
	// point 1
	_rect_vertex_buffer_data[index++] = -0.5f * factor;
	_rect_vertex_buffer_data[index++] = -0.5f * factor;
	_rect_vertex_buffer_data[index++] = 0.0f * factor;
	// point 2
	_rect_vertex_buffer_data[index++] = 0.5f * factor;
	_rect_vertex_buffer_data[index++] = -0.5f * factor;
	_rect_vertex_buffer_data[index++] = 0.0f * factor;
	// point 3
	_rect_vertex_buffer_data[index++] = 0.5f * factor;
	_rect_vertex_buffer_data[index++] = 0.5f * factor;
	_rect_vertex_buffer_data[index++] = 0.0f * factor;

	// vbo
	int dataCnt = index;
	glGenBuffers(1, &_vboVertexPos);
	glBindBuffer(GL_ARRAY_BUFFER, _vboVertexPos);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * dataCnt, _rect_vertex_buffer_data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// vao
	glGenVertexArrays(1, &_vaoHandle);

	_verticeCnt = 6;

	delete[] _rect_vertex_buffer_data;
	_rect_vertex_buffer_data = nullptr;
}

void ModelComponent::update(float deltaTime) {

}

void ModelComponent::draw(glm::mat4& modelMatrix, glm::mat4& viewMatrix, glm::mat4 projectionMatrix) {

	if (!hasInit()) {
		return;
	}
	
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);	// 这里的 3 的 含义是顶点之间 stride 是 3 ,与shader 、顶点格式密切相关

	// do draw
	glDrawArrays(GL_TRIANGLES, 0, _verticeCnt);

	// after draw
	glUseProgram(0);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}
