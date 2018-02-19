
#ifndef __BMP_LOADER_HPP__
#define __BMP_LOADER_HPP__

#include <iostream>
#include <assert.h>
#include <math.h>

class The24BitBmp
{
public:
    ~The24BitBmp()
    {
        delete[] data;
        data = nullptr;
    }
    
    long fileSize;
    long dataOffset;
    
    int width;
    int height;
    
    char* data;
    
    int fillZeroPerLine;
    int sizePerLine;
    
    unsigned char getRAt(int x, int y);
    unsigned char getGAt(int x, int y);
    unsigned char getBAt(int x, int y);
    char* getAddrAt(int x, int y);
};


void loadBmp(std::string file,The24BitBmp& bitmap);


#endif //__BMP_LOADER_HPP__

