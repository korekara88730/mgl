
#include "VertexObject.hpp"
#include <stdio.h>
#include "common/Shader.hpp"

VertexObject::VertexObject()
:_vao(0)
,_vbo(0)
,_vboColor(0)
,_programID(0)
{

}

VertexObject::~VertexObject()
{
    cleanData();
}


void VertexObject::prepareData()
{
    GLfloat vertexPosData[3 * 6 * 6] = {
        // front
        -1,-1,1,
        -1,1,1,
        1,-1,1,

        -1,1,1,
        1,-1,1,
        1,1,1,
        
        // back
        -1,-1,-1,
        -1,1,-1,
        1,-1,-1,
        
        -1,1,-1,
        1,-1,-1,
        1,1,-1,
        
        // up
        -1,1,1,
        -1,1,-1,
        1,1,1,
        
        -1,1,-1,
        1,1,1,
        1,1,-1,
        
        // bottom
        -1,-1,1,
        -1,-1,-1,
        1,-1,1,
        
        -1,-1,-1,
        1,-1,1,
        1,-1,-1,
        
        // right
        
        1,-1,1,
        1,1,1,
        1,-1,-1,
        
        1,1,1,
        1,-1,-1,
        1,1,-1,
        
        // left
        
        -1,-1,1,
        -1,1,1,
        -1,-1,-1,
        
        -1,1,1,
        -1,-1,-1,
        -1,1,-1,
    };
    
    
    /*
    GLfloat vertexColorData[3 * 6 * 6] = {
        // front
        1,0,0,
        0,1,0,
        0,0,1,
        
        1,1,0,
        1,1,1,
        1,0,1,
        
        // back
        1,0,0,
        0,1,0,
        0,0,1,
        
        1,1,0,
        1,1,1,
        1,0,1,
        
        // up
        1,0,0,
        0,1,0,
        0,0,1,
        
        1,1,0,
        1,1,1,
        1,0,1,
        
        // bottom
        1,0,0,
        0,1,0,
        0,0,1,
        
        1,1,0,
        1,1,1,
        1,0,1,
        
        // right
        1,0,0,
        0,1,0,
        0,0,1,
        
        1,1,0,
        1,1,1,
        1,0,1,
        
        // left
        1,0,0,
        0,1,0,
        0,0,1,
        
        1,1,0,
        1,1,1,
        1,0,1,
    };
     */

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
    
    // gen color VBO
    glGenBuffers(1,&_vboColor);
    /*
    glBindBuffer(GL_ARRAY_BUFFER,_vboColor);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexColorData),vertexColorData,GL_STATIC_DRAW);
     */
    
    // finish bind
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
}

void VertexObject::doDraw(int viewportW,int viewportH)
{
    // gen vertex color data
    GLfloat vertexColorData[3 * 6 * 6];
    for (int v = 0; v < 6 * 6 ; v++) {
        vertexColorData[v * 3 + 0] = (float)(rand() % 100) / 100;
        vertexColorData[v * 3 + 1] = (float)(rand() % 100) / 100;
        vertexColorData[v * 3 + 2] = (float)(rand() % 100) / 100;
    }
    glBindBuffer(GL_ARRAY_BUFFER,_vboColor);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexColorData),vertexColorData,GL_STREAM_DRAW);
    
    
    // do draw vertice
    glBindVertexArray(_vao);
    glBindBuffer(GL_ARRAY_BUFFER,_vbo);
    glUseProgram(_programID);
    
    // pass param to shader
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(GL_FLOAT),(void*)0);
//    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6 * sizeof(GL_FLOAT),(void*)(sizeof(GL_FLOAT) * 3));
    
    // color data to shader
    glBindBuffer(GL_ARRAY_BUFFER,_vboColor);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,3 * sizeof(GL_FLOAT),(void*)0);
    
    // mvp param to shader
    glm::mat4 modelMatrix = glm::mat4(1.0f);
    glm::mat4 viewMatrix = glm::lookAt(glm::vec3(4,3,3),
                                       glm::vec3(0,0,0),
                                       glm::vec3(0,1,0));
    float fovyAngle = 45;
    float aspectWH = (float)viewportW/(float)viewportH;
    float zNear = 0.1f;
    float zFar = 100.f;
    glm::mat4 projectMatrix = glm::perspective(glm::radians(fovyAngle),aspectWH,zNear,zFar);
//    glm::mat4 projectMatrix = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f);
    glm::mat4 mvp = projectMatrix * viewMatrix * modelMatrix;
    
    GLuint matrixID = glGetUniformLocation(_programID,"MVP");
    glUniformMatrix4fv(matrixID,1,GL_FALSE,&mvp[0][0]);

    
//    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawArrays(GL_TRIANGLES, 0, 36);

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
    if(_vboColor != 0)
    {
        glDeleteBuffers(1,&_vboColor);
        _vboColor = 0;
    }
    if(_programID != 0)
    {
        glDeleteProgram(_programID);
        _programID = 0;
    }
}
