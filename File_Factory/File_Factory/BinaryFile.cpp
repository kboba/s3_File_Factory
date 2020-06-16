#include <stdio.h>
#include <fstream>

#include "BinaryFile.h"
    
BinaryFile::BinaryFile(std::string path, std::string mode) : iFile(path, mode) {}


BinaryFile::~BinaryFile() {}


iFile::FileError BinaryFile::write(const std::vector<Point>& points)
{
    if (!file.is_open())
    {
        return FileError::FileClosed;
    }
    if (!(openMode & std::fstream::out))
    {
        return FileError::OperationNotPermitted;
    }

    Point point_ff;
    std::vector<Point>::const_iterator i = points.begin();

    while (i != points.end())
    {
        point_ff = *i;
        file.write((char*)&point_ff, sizeof(Point));
        i++;
    }
    return FileError::SUCCESS;

}


iFile::FileError BinaryFile::read(std::vector<Point>& points)
{
    if (!file.is_open())
    {
        return FileError::FileClosed;
    }
    if (!(openMode & std::fstream::in))
    {
        return FileError::OperationNotPermitted;
    }

    points.clear();
    
    Point point_ff;
    while (!file.eof())
    {
        file.read((char*)&point_ff, sizeof(Point));
        points.push_back(point_ff);
    }
    return FileError::SUCCESS;
}


iFile::FileError BinaryFile::read(Point& p, int idx)
{
    if (!file.is_open())
    {
        return FileError::FileClosed;
    }
    else if (!(openMode & std::fstream::in))
    {
        return FileError::OperationNotPermitted;
    }
    else if ( (size < sizeof(Point)*idx) || (idx < 1) )
    {
        return FileError::OUT_OF_BOUNDS;
    }
    else
    { 
        file.seekg(sizeof(Point)*(idx - 1), file.beg);
        file.read((char*) &p, sizeof(Point));

        return FileError::SUCCESS;
    }
}


