
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
    
private:
    float* _verticePosData;
    float* _verticeUVData;
    float* _verticeNormalData;
    
private:
//    GLuint  _vao;
    GLuint  _vboPos;
//    GLuint  _vboUV;
//    GLuint  _vboNormal;
    
    
    int _faceCnt;
    
};

ObjModel* loadObj(std::string path);
#endif /* ObjLoader_hpp */
