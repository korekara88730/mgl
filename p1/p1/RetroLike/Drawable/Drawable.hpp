//
//  Drawable.hpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#ifndef Drawable_hpp
#define Drawable_hpp

#include <stdio.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <map>

class Drawable {
public:
    Drawable();
    virtual ~Drawable();
    
    virtual void draw(glm::mat4& modelMatrix, glm::mat4& viewMatrix, glm::mat4 projectionMatrix) = 0;


protected:

    
};


typedef enum {
	DT_Cube,
	DT_Triangle,
	DT_Rectangle,
	DT_CustomModel,

	DT_Max,

} DrawableType;

class DrawableManager {


public:
	~DrawableManager();
	static DrawableManager* getInstance();

	void initAllResource();
	void cleanAllResource();

	Drawable* getModel(DrawableType modelType);

private:
	DrawableManager();


private:
	std::map<DrawableType,Drawable*>	_resHash;
};


#endif /* Drawable_hpp */
