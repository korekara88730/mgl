
#ifndef ObjLoader_hpp
#define ObjLoader_hpp

#include <stdio.h>
#include <iostream>
#include "cJSON.h"
#include <GL/glew.h>

class ObjModel
{
public:
    ObjModel();
    virtual ~ObjModel();
    void initWithJson(cJSON* pJson);
    
    GLuint getPosVBO(){ return _vboPos;}
    int getFaceCnt(){ return _faceCnt;}
    int getVerticeCnt(){ return _verticeCnt; }
    
private:
    GLfloat* _verticePosData;
    GLfloat* _verticeUVData;
    GLfloat* _verticeNormalData;
    
private:
//    GLuint  _vao;
    GLuint  _vboPos;
//    GLuint  _vboUV;
//    GLuint  _vboNormal;
    
    
    int _faceCnt;
    int _verticeCnt;
    
};

ObjModel* loadObj(std::string path);
#endif /* ObjLoader_hpp */
