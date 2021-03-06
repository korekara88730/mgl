
#ifndef VertexObject_hpp
#define VertexObject_hpp

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "imgloader/BmpLoader.hpp"
#include "objloader/ObjLoader.hpp"

class VertexObject
{
public:
    VertexObject();
    virtual ~VertexObject();
    
    void prepareData();
    void doDraw(int viewportW,int viewportH,glm::mat4& viewMatrix,glm::mat4& projectionMatrix);
    void cleanData();
    
//private:
//    void prepareFakeData();
//
    
private:
    void prepareTexture();
    void prepareModel();
    
private:
    GLuint  _vao;
    GLuint  _vbo;
    GLuint  _vboColor;
    GLuint  _vboUV;
    GLuint  _programID;
    
    GLuint  _texID1;
    ObjModel*   _model;
    
    
};

#endif /* VertexObject_hpp */
