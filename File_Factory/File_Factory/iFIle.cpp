#include"iFile.h"

iFile::iFile(const std::string path, const std::string mode)
{
    if (mode.find("r") != std::string::npos) openMode |= std::fstream::in;
    if (mode.find("w") != std::string::npos) openMode |= std::fstream::out;
    if (mode.find("a") != std::string::npos) openMode |= std::fstream::app;
    if (mode.find("t") != std::string::npos) openMode |= std::fstream::trunc;
    if (mode.find("b") != std::string::npos) openMode |= std::fstream::binary;

    openMode |= std::fstream::ate;
    file.open(path, openMode);
    size = file.tellg();
    
    if (mode.find("e") != std::string::npos) 
        file.seekg(0, std::fstream::end);
    else
        file.seekg(0, std::fstream::beg);
}

iFile::~iFile()
{
    file.close();
}
