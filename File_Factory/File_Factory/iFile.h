#pragma once
#include <iostream>
#include<fstream>
#include<vector>
#include<string>

#include "defines.h"

class iFile
{
protected:
    std::fstream file;
    std::string path;
    unsigned int size;
    std::fstream::openmode openMode;

public:
    enum class FileError 
    {
        SUCCESS,
        OUT_OF_BOUNDS,
        FILE_INVALID,
        OperationNotPermitted,
        FileClosed
    };

    virtual FileError write(const std::vector<Point>& points) = 0;
    virtual FileError read(std::vector<Point>& points) = 0;
    virtual FileError read(Point& p, const int idx)=0;

    iFile(const std::string path, const std::string mode);
    ~iFile();
};
