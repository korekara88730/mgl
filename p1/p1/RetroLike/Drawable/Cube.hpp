//
//  Cube.hpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp

#include <stdio.h>
#include "Drawable.hpp"
#include <glm/glm.hpp>
#include "../../common/Shader.hpp"

class Cube : public Drawable {
public:
    Cube();
    virtual ~Cube();
    
	void init(p1sh::ShaderType shaderType,int size);
    virtual void draw(glm::mat4& modelMatrix, glm::mat4& viewMatrix, glm::mat4 projectionMatrix) override;

private:
	void initVerticeData();

private:
    int					_size = 1;
	p1sh::ShaderType	_shadertype;

	// vao
	GLuint		_vaoHandle = 0;
	// shader
	GLuint		_shaderHandle = 0;
	// vbo ,vertice position.May extend other properties
	GLuint		_vboVerticePos = 0;

};


#endif /* Cube_hpp */
