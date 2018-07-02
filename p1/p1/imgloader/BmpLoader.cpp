#define _CRT_SECURE_NO_WARNINGS
#include "BmpLoader.hpp"

unsigned char The24BitBmp::getRAt(int x, int y)
{
    char* addr = getAddrAt(x, y);
    char col = addr[2];
    return col;
}

unsigned char The24BitBmp::getGAt(int x, int y)
{
    char* addr = getAddrAt(x, y);
    char col = addr[1];
    return col;
}

unsigned char The24BitBmp::getBAt(int x, int y)
{
    char* addr = getAddrAt(x, y);
    char col = addr[0];
    return col;
}

char* The24BitBmp::getAddrAt(int x, int y)
{
    long offset = sizePerLine * y + x * 3;
    return this->data + offset;
}


long fileSize(FILE* fp)
{
    fseek(fp, 0L, SEEK_END);
    long pos = ftell(fp);
    fseek(fp,0L,SEEK_SET);
    return pos;
}

/*
 addr 地址
 bytes 多少字节 (每个字节是8位)
 */
int getDecimal(char* addr,int bytes)
{
    int ret = 0;
    assert(bytes%2 == 0);
    for (int index = 0; index < bytes;index++)
    {
        int base = addr[index];
        int pownum = index * 2;
        int inc = base * pow(16, pownum);
        //printf("base:%d,pownum:%d,inc:%d\n",base,pownum,inc);
        ret += inc;
    }
    return ret;
}

void loadBmp(std::string file,The24BitBmp& bitmap)
{
    FILE*   fp = fopen(file.c_str(), "rb");
    if (fp == nullptr) return;
    
    long size = fileSize(fp);
    
    char* fd = new char[size];
    
    
    for (long index = 0; index < size;index++)
    {
        fd[index] = 0;
    }
    
    fread(fd, size,1, fp);
    fclose(fp);
    
    bitmap.dataOffset = getDecimal(fd + 10, 4);
    bitmap.fileSize = getDecimal(fd + 2, 4);
    bitmap.width = getDecimal(fd + 18, 4);
    bitmap.height = getDecimal(fd + 22, 4);
    long dataSize = bitmap.fileSize - bitmap.dataOffset;
    bitmap.data = new char[dataSize]();
    memcpy(bitmap.data, fd + bitmap.dataOffset, dataSize);
    
    
    int shouldBytesPerLine = bitmap.width * 3;
    bitmap.fillZeroPerLine = 0;
    if (shouldBytesPerLine %4 != 0)
    {
        printf("123");
    }
    
    bitmap.sizePerLine = shouldBytesPerLine + bitmap.fillZeroPerLine;
    delete[] fd;
    
}

