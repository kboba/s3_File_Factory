#pragma once
#include "iFile.h"

class BinaryFile : public iFile 
{
public:
    BinaryFile(std::string path, std::string mode);
    ~BinaryFile();

    FileError write(const std::vector<Point>& points);
    FileError read(std::vector<Point>& points);
    FileError read(Point& p, int idx);
};

