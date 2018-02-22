//
//  ObjLoader.cpp
//  p1
//
//  Created by miaoyunlong on 21/02/2018.
//  Copyright © 2018 playcrab. All rights reserved.
//

#include "ObjLoader.hpp"
#include "cJSON.h"

#include <fstream>
#include <iostream>
#include <sstream>

ObjModel* loadObj(std::string path)
{
    std::string strJson;
    std::ifstream jsonFileStream(path,std::ios::in);
    if(jsonFileStream.is_open())
    {
        std::stringstream sstr;
        sstr << jsonFileStream.rdbuf();
        strJson = sstr.str();
        jsonFileStream.close();
    }
    else
    {
        printf("Can not load json file:%s\n",path.c_str());
    }
    
    
    cJSON* pJson = cJSON_Parse(strJson.c_str());
    if(!pJson)
    {
        printf("Can not parse JSON object.");
    }
    
    
    ObjModel* pObj = new ObjModel();
    printf("%s",path.c_str());
    return pObj;
}


