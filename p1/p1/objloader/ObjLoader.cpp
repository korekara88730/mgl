
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
    
    int posDataLen = faceCnt * FACE_VERTICE_CNT * 3;
    _verticePosData = new GLfloat[posDataLen];
    
    _verticeCnt = posDataLen;
    
    int subscriptIndex = 0;
    for(int index = 0;index < faceCnt;index++)
    {
        cJSON* faceData = cJSON_GetArrayItem(faces,index);
        for(int vIndex = 0;vIndex < FACE_VERTICE_CNT;vIndex++)
        {
            cJSON* vertexPosData = cJSON_GetObjectItem(cJSON_GetArrayItem(faceData,vIndex),"vertexIndex");
            int vertexIndex = vertexPosData->valueint;
            cJSON* allVertice = cJSON_GetObjectItem(pJson,"vertice");
            GLfloat x = (GLfloat)cJSON_GetObjectItem(cJSON_GetArrayItem(allVertice,vertexIndex - 1),"x")->valuedouble;
            GLfloat y = (GLfloat)cJSON_GetObjectItem(cJSON_GetArrayItem(allVertice,vertexIndex - 1),"y")->valuedouble;
            GLfloat z = (GLfloat)cJSON_GetObjectItem(cJSON_GetArrayItem(allVertice,vertexIndex - 1),"z")->valuedouble;
            
            // @miao @todo
            // 这里 下标 计算有 bug ！
            _verticePosData[subscriptIndex++] = x;
            _verticePosData[subscriptIndex++] = y;
            _verticePosData[subscriptIndex++] = z;
        }
    }
    // gen pos vbo
    glGenBuffers(1,&_vboPos);
    glBindBuffer(GL_ARRAY_BUFFER,_vboPos);
    //glBufferData(GL_ARRAY_BUFFER,sizeof(_verticePosData),_verticePosData,GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat) * posDataLen,_verticePosData,GL_STATIC_DRAW);
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
    
    ObjModel* pObj = new ObjModel();
    pObj->initWithJson(pJson);
    return pObj;
}


