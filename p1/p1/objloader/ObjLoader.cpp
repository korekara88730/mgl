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


static const int FACE_VERTICE_CNT = 3;

ObjModel::ObjModel()
:_verticePosData(nullptr)
,_verticeUVData(nullptr)
,_verticeNormalData(nullptr)
//,_vao(0)
,_vboPos(0)
//,_vboUV(0)
//,_vboNormal(0)
,_faceCnt(0)
{
    
}

ObjModel::~ObjModel()
{
    
}

void ObjModel::initWithJson(cJSON* pJson)
{
    cJSON* faces = cJSON_GetObjectItem(pJson,"faces");
    int faceCnt = cJSON_GetArraySize(faces);
    
    _faceCnt = faceCnt;
    
    int posDataLen = faceCnt * FACE_VERTICE_CNT;
    _verticePosData = new float[posDataLen];
    for(int index = 0;index < faceCnt;index++)
    {
        cJSON* faceData = cJSON_GetArrayItem(faces,index);
        for(int vIndex = 0;vIndex < FACE_VERTICE_CNT;vIndex++)
        {
            cJSON* vertexPosData = cJSON_GetObjectItem(cJSON_GetArrayItem(faceData,vIndex),"vertexIndex");
            int vertexIndex = vertexPosData->valueint;
            cJSON* allVertice = cJSON_GetObjectItem(pJson,"vertice");
            float x = (float)cJSON_GetObjectItem(cJSON_GetArrayItem(allVertice,vertexIndex - 1),"x")->valuedouble;
            float y = (float)cJSON_GetObjectItem(cJSON_GetArrayItem(allVertice,vertexIndex - 1),"y")->valuedouble;
            float z = (float)cJSON_GetObjectItem(cJSON_GetArrayItem(allVertice,vertexIndex - 1),"z")->valuedouble;
            _verticePosData[index * FACE_VERTICE_CNT + vIndex] = x;
            _verticePosData[index * FACE_VERTICE_CNT + vIndex] = y;
            _verticePosData[index * FACE_VERTICE_CNT + vIndex] = z;
        }
    }
    // gen pos vbo
    glGenBuffers(1,&_vboPos);
    glBindBuffer(GL_ARRAY_BUFFER,_vboPos);
    glBufferData(GL_ARRAY_BUFFER,sizeof(_verticePosData),_verticePosData,GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

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
    // test json case
    /*
    cJSON* vertice = cJSON_GetObjectItem(pJson,"vertice");
    int verticeCnt = cJSON_GetArraySize(vertice);

    cJSON* item = cJSON_GetArrayItem(vertice,1);
    
    float val = item->valuedouble;
    
    cJSON* test = cJSON_GetObjectItem(pJson,"xxx");
    */
    
    ObjModel* pObj = new ObjModel();
    pObj->initWithJson(pJson);
    return pObj;
}


