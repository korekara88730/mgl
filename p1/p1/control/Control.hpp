#ifndef __CONTROL_HPP__
#define __CONTROL_HPP__

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <GLFW/glfw3.h>

class Control
{
public:
    Control();
    virtual ~Control();
    void computeMatricesFromInputs(GLFWwindow* pWindow,float deltaTime);
    
    glm::mat4 getViewMatrix()
    {
        return _viewMatrix;
    };
    
    glm::mat4 getProjectionMatrix()
    {
        return _projectionMatrix;
    };
    
private:
    glm::vec3 _position;
    float _horizontalAngle;
    float _verticalAngle;
    float _initialFoV;
    
    float _speed;
    float _mouseSpeed;
    
    
private:
    // result
    glm::mat4 _viewMatrix;
    glm::mat4 _projectionMatrix;
};

#endif //__CONTROL_HPP__
