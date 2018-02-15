
#include "VertexObject.hpp"
#include <stdio.h>
#include "common/Shader.hpp"


VertexObject::VertexObject()
:_vao(0)
,_vbo(0)
,_programID(0)
{

}

VertexObject::~VertexObject()
{
    cleanData();
}


void VertexObject::prepareData()
{
    GLfloat vertexPosData[9 * 2] = {
        -1,-1,0,        // p1 pos
        1,0,0,          // p1 color
        
        1,-1,0,         // p2 pos
        0,1,0,          // p2 color
        
        0,1,0,          // p3 pos
        0,0,1,          // p3 color
    };

//    GLfloat vertexPosData[9 * 2] = {
//        -1,-1,0,        // p1 pos
//        1,0,0,          // p1 color
//
//        0,1,0,          // p3 pos
//        0,1,0,          // p3 color
//
//        1,-1,0,         // p2 pos
//        0,0,1,          // p2 color
//
//    };


    // gen VAO
    glGenVertexArrays(1,&_vao);
//    glBindVertexArray(_vao);  // 这一步 没用。只有在 glUseProgram(),glEnableVertexAttribArray(),glVertexAttriPointer() 这种操作shader 和 给 shader 传数据的场合 ，之前 glBindVertexArray() 才有用
    // gen VBO
    glGenBuffers(1,&_vbo);
    glBindBuffer(GL_ARRAY_BUFFER,_vbo);
    // pass data to VBO
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexPosData),vertexPosData,GL_STATIC_DRAW);
    // shader
    _programID = LoadShaders("./shaders/SimpleVertexShader.vertexshader","./shaders/SimpleFragmentShader.fragmentshader");
    
    // finish bind
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
}

void VertexObject::prepareFakeData()
{
    
}

void VertexObject::doDraw()
{
    glBindVertexArray(_vao);
    glBindBuffer(GL_ARRAY_BUFFER,_vbo);
    glUseProgram(_programID);
    
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6 * sizeof(GL_FLOAT),(void*)0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6 * sizeof(GL_FLOAT),(void*)(sizeof(GL_FLOAT) * 3));
//    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 3* GL_FLOAT,(void*)0);
//    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,3*GL_FLOAT,(void*)0);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glUseProgram(0);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    
}

void VertexObject::cleanData()
{
    if(_vao != 0)
    {
        glDeleteVertexArrays(1,&_vao);
        _vao = 0;
    }
    if(_vbo != 0)
    {
        glDeleteBuffers(1,&_vbo);
        _vbo = 0;
    }
    if(_programID != 0)
    {
        glDeleteProgram(_programID);
        _programID = 0;
    }
}
