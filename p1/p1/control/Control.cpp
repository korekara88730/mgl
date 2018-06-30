
#include "Control.hpp"


const bool bEnableMouse = true;

Control::Control()
:_position(glm::vec3( 0, 0, 500 ))
,_horizontalAngle(3.14f)
,_verticalAngle(0.0f)
,_initialFoV(45.0f)
,_speed(30.0f)
,_mouseSpeed(0.005f)
//,_mouseSpeed(0.0001f)
{
    
}

Control::~Control()
{
    
}

void Control::computeMatricesFromInputs(GLFWwindow* pWindow,float deltaTime)
{
    double xpos,ypos;
    glfwGetCursorPos(pWindow,&xpos,&ypos);
//    printf("cursor:(%.3f,%.3f)\n",xpos,ypos);
    
    int winWidth,winHeight;
    glfwGetWindowSize(pWindow,&winWidth,&winHeight);
    glfwSetCursorPos(pWindow,winWidth/2,winHeight/2);
    
    float deltaX = float(winWidth/2 - xpos);
    float deltaY = float(winHeight/2 - ypos);
//    printf("mouse x,y:(%.3f,%.3f)\n",xpos,ypos);
    
    if(bEnableMouse){
        _horizontalAngle += _mouseSpeed * deltaX;
        _verticalAngle += _mouseSpeed * deltaY;
    }
    
    
    glm::vec3 direction(
        cos(_verticalAngle) * sin(_horizontalAngle),
        sin(_verticalAngle),
        cos(_verticalAngle) * cos(_horizontalAngle)
    );
    
    glm::vec3 right = glm::vec3(
        sin(_horizontalAngle - 3.14f/2.0f),
        0,
        cos(_horizontalAngle - 3.14f/2.0f)
    );
    
    glm::vec3 up = glm::cross(right,direction);
    
    // Move forward
    if (glfwGetKey( pWindow, GLFW_KEY_UP ) == GLFW_PRESS){
        _position += direction * deltaTime * _speed;
    }
    // Move backward
    if (glfwGetKey( pWindow, GLFW_KEY_DOWN ) == GLFW_PRESS){
        _position -= direction * deltaTime * _speed;
    }
    // Strafe right
    if (glfwGetKey( pWindow, GLFW_KEY_RIGHT ) == GLFW_PRESS){
        _position += right * deltaTime * _speed;
    }
    // Strafe left
    if (glfwGetKey( pWindow, GLFW_KEY_LEFT ) == GLFW_PRESS){
        _position -= right * deltaTime * _speed;
    }
    
    // result
    float FoV = _initialFoV;
    _projectionMatrix = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 10000.0f);
    _viewMatrix = glm::lookAt(
        _position,           // Camera is here
        _position+direction, // and looks here : at the same position, plus "direction"
        up                  // Head is up (set to 0,-1,0 to look upside-down)
    );
    
}
