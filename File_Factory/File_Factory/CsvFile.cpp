#include <sstream>

#include "CsvFile.h"

CsvFile::CsvFile(std::string path, std::string mode) : iFile(path, mode) {}

CsvFile::~CsvFile() {}

void CsvFile::writeLine(const Point& p) 
{
    file << p.x << "," << p.y << "," << p.z << std::endl;
}

std::vector<std::string> CsvFile::split(std::string str, char delim) 
{
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;

}



iFile::FileError CsvFile::write(const std::vector<Point>& points) 
{
    if (!file.is_open()) 
        return FileError::FileClosed;
    
    if (!(openMode & std::fstream::out)) 
        return FileError::OperationNotPermitted;
    
    for (auto p : points) {
        writeLine(p);
    }
    return FileError::SUCCESS;
}


iFile::FileError CsvFile::read(std::vector<Point>& points) 
{
    if (!file.is_open()) 
        return FileError::FileClosed;

    if (!(openMode & std::fstream::in)) 
        return FileError::OperationNotPermitted;
    
    points.clear();
    std::string str;
    while (std::getline(file, str)) 
    {
        auto values = split(str, ',');
        if (values.size() == 3)
        {
            points.push_back(Point(
                stod(values[0]),
                stod(values[1]),
                stod(values[2])
            ));
        }
        else
            return FileError::FILE_INVALID;
    }
    return FileError::SUCCESS;
}


iFile::FileError CsvFile::read(Point& p, int idx)
{
    iFile::FileError error;
    std::string str;
    if (!file.is_open())
        return iFile::FileError::FileClosed;
    
    if (!(openMode & std::fstream::in))
        return FileError::OperationNotPermitted;

    if (idx < 1)
        return FileError::OUT_OF_BOUNDS;
    
    file.seekg(0, std::fstream::beg);

    for (int i = 0; (i < (idx - 1)) & !file.eof(); i++)
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    error = (file.eof()) ? FileError::OUT_OF_BOUNDS : FileError::SUCCESS;

    getline(file, str);
    if (!(str == ""))
    {
        auto values = split(str, ',');
        if (values.size() == 3)
        {
            p.x = stod(values[0]);
            p.y = stod(values[1]);
            p.z = stod(values[2]);
        }
        else
            return FileError::FILE_INVALID;
    }
    

    return error;
}
