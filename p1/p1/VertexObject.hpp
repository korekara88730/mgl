
#ifndef VertexObject_hpp
#define VertexObject_hpp

#include <GL/glew.h>

class VertexObject
{
public:
    VertexObject();
    virtual ~VertexObject();
    
    void prepareData();
    void doDraw();
    void cleanData();
    
private:
    void prepareFakeData();
    
private:
    GLuint  _vao;
    GLuint  _vbo;
    GLuint  _programID;
};

#endif /* VertexObject_hpp */
