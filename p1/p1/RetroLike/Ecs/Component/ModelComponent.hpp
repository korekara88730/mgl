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
	typedef enum {
		MT_Triangle,
		MT_Cube,
		MT_Rectangle,

		MT_Max,
	} EModelType;

public:
    ModelComponent();
    virtual ~ModelComponent();
    
	void init(EModelType modelType);

public:
	void update(float deltaTime);
	void draw(glm::mat4& modelMatrix,glm::mat4& viewMatrix,glm::mat4 projectionMatrix);

    

private:
    void initVertexDataBaseTriangle();
	void initVertexDataCube();
	void initVertexDataRectangle();

	bool hasInit() { return _modelType != EModelType::MT_Max; }

private:
	// triangle
    static const int TRIANGLE_VERTEX_SIZE = 9;  // 3 for each vertex,3 vertex.
    GLfloat* _triangle_vertex_buffer_data;

	// cube
	
	// rectangle
	static const int RECTANGLE_VERTEX_SIZE = 3*6;	// 3 for each vertex,6 vertex
	GLfloat*	_rect_vertex_buffer_data;


	// vertice count 
	int _verticeCnt = 0;

	// vao
	GLuint	_vaoHandle;
	// vbo vertex pos
	GLuint	_vboVertexPos;
	// shader
	GLuint	_shaderHandle;


private:
	EModelType	_modelType = MT_Max;
	
};

#endif /* ModelComponent_hpp */
