#pragma once
#include "iFile.h"

class CsvFile : public iFile
{
    void writeLine(const Point& p);
    std::vector<std::string> split(std::string std, char delim);

public:
    CsvFile(std::string path, std::string mode);
    ~CsvFile();

    FileError write(const std::vector<Point>& points);
    FileError read(std::vector<Point>& points);
    FileError read(Point& p, int idx);
};

