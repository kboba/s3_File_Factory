#include "FileFactory.h"
#include "CsvFile.h"
#include "BinaryFile.h"

iFile* FileFactory::OpenFile(std::string path, std::string mode)
{
    if (path.substr(path.length()-3, 3) == "csv")
    {
        return new CsvFile(path, mode);
    }
    else if (path.substr(path.length()-3, 3) == "bin")
    {
        return new BinaryFile(path, mode);
    }
    return nullptr;
}
