//
//  Drawable.cpp
//  p1
//
//  Created by miaoyunlong on 30/06/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "Drawable.hpp"
#include "Cube.hpp"

Drawable::Drawable() {
    
    
}

Drawable::~Drawable() {
    
    
}

DrawableManager::DrawableManager() {

}

DrawableManager::~DrawableManager() {
	cleanAllResource();
}

DrawableManager* DrawableManager::getInstance() {
	static DrawableManager instance;
	return &instance;
}

void DrawableManager::initAllResource() {
	// cube
	auto cube = new Cube();
	cube->init(p1sh::ShaderType::ST_MVP, 1);
	_resHash[DrawableType::DT_Cube] = cube;

	// triangle

	// rectangle

	// custom model

}

void DrawableManager::cleanAllResource() {
	for (auto iter = _resHash.begin(); iter != _resHash.end();++iter) {
		Drawable* pDrawable = iter->second;
		delete pDrawable;
	}
	_resHash.clear();
}

Drawable* DrawableManager::getModel(DrawableType modelType) {
	Drawable* pResult = nullptr;
	if (_resHash.find(modelType) != _resHash.end()) {
		return _resHash[modelType];
	}
	return pResult;
}

