#pragma once
#include"iFile.h"

class FileFactory
{
public:
    static iFile* OpenFile(std::string path, std::string mode);
};
