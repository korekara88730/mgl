
#include "VertexObject.hpp"
#include <stdio.h>
#include "common/Shader.hpp"
#include "objloader/ObjLoader.hpp"


VertexObject::VertexObject()
:_vao(0)
,_vbo(0)
,_vboColor(0)
,_vboUV(0)
,_programID(0)
,_texID1(0)
,_model(nullptr)
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
    
    
    GLfloat vertexUVData[2 * 6 * 6] = {
        // front
        0,0,
        0,1,
        1,0,
        
        0,1,
        1,0,
        1,1,
        
        // back
        0,0,
        0,1,
        1,0,
        
        0,1,
        1,0,
        1,1,
        
        // up
        0,0,
        0,1,
        1,0,
        
        0,1,
        1,0,
        1,1,
        
        // bottom
        0,0,
        0,1,
        1,0,
        
        0,1,
        1,0,
        1,1,
        
        
        // right
        0,0,
        0,1,
        1,0,
        
        0,1,
        1,0,
        1,1,
        
        
        // left
        0,0,
        0,1,
        1,0,
        
        0,1,
        1,0,
        1,1,
    };


    // gen VAO
    glGenVertexArrays(1,&_vao);
    
    // gen VBO
    glGenBuffers(1,&_vbo);
    glBindBuffer(GL_ARRAY_BUFFER,_vbo);
    // pass data to VBO
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexPosData),vertexPosData,GL_STATIC_DRAW);
    // shader
    _programID = LoadShaders("./shaders/SimpleVertexShader.vertexshader","./shaders/SimpleFragmentShader.fragmentshader");
    
    // gen UV vbo
    glGenBuffers(1,&_vboUV);
    glBindBuffer(GL_ARRAY_BUFFER,_vboUV);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexUVData),vertexUVData,GL_STATIC_DRAW);

    // finish bind
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
    
    
    prepareTexture();
    prepareModel();
}

void VertexObject::doDraw(int viewportW,int viewportH,glm::mat4& viewMatrix,glm::mat4& projectionMatrix)
{
    /*
    // gen vertex color data
    GLfloat vertexColorData[3 * 6 * 6];
    for (int v = 0; v < 6 * 6 ; v++) {
        vertexColorData[v * 3 + 0] = (float)(rand() % 100) / 100;
        vertexColorData[v * 3 + 1] = (float)(rand() % 100) / 100;
        vertexColorData[v * 3 + 2] = (float)(rand() % 100) / 100;
    }
    glBindBuffer(GL_ARRAY_BUFFER,_vboColor);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexColorData),vertexColorData,GL_STREAM_DRAW);
    */
    
    // do draw vertice
    glBindVertexArray(_vao);
    
    // @miao @todo
    glBindBuffer(GL_ARRAY_BUFFER,_vbo);
//    glBindBuffer(GL_ARRAY_BUFFER,_model->getPosVBO());
    glUseProgram(_programID);
    
    // pass param to shader
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(GL_FLOAT),(void*)0);
//    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6 * sizeof(GL_FLOAT),(void*)(sizeof(GL_FLOAT) * 3));
    
//     uv data to shader
    glBindBuffer(GL_ARRAY_BUFFER,_vboUV);
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,2 * sizeof(GL_FLOAT),(void*)0);
    
    // mvp param to shader
    glm::mat4 modelMatrix = glm::mat4(1.0f);
    glm::mat4 mvp = projectionMatrix * viewMatrix * modelMatrix;
    GLuint matrixID = glGetUniformLocation(_programID,"MVP");
    glUniformMatrix4fv(matrixID,1,GL_FALSE,&mvp[0][0]);

    
    // texture
     glBindTexture(GL_TEXTURE_2D,_texID1);
    
//    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glUseProgram(0);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindTexture(GL_TEXTURE_2D,0);
    
    
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
    if(_vboUV != 0)
    {
        glDeleteBuffers(1,&_vboUV);
        _vboUV = 0;
    }
    if(_programID != 0)
    {
        glDeleteProgram(_programID);
        _programID = 0;
    }
    
    if(_texID1 != 0)
    {
        glDeleteTextures(1,&_texID1);
    }
}


void VertexObject::prepareTexture()
{
    The24BitBmp bitmap;
    loadBmp("bmp/laoshi.bmp",bitmap);
    
    glGenTextures(1,&_texID1);
    glBindTexture(GL_TEXTURE_2D,_texID1);
    
//  glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,bitmap.width,bitmap.height,0,GL_BGR,GL_UNSIGNED_BYTE,bitmap.data);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    glBindTexture(GL_TEXTURE_2D,0);
}


void VertexObject::prepareModel()
{
//    loadObj("./obj");
//    loadObj("./json/test.json");
//    loadObj("./json/test2.json");
    _model = loadObj("./model/box.obj.json");
}
