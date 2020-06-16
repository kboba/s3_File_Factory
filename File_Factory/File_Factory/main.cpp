#include "FileFactory.h"
#include "CsvFile.h"
#include "BinaryFile.h"


int main()
{
    std::vector<Point> points;
    Point point;
    iFile::FileError file_error;

    std::cout << std::endl;
    iFile* file_csv = FileFactory::OpenFile("test.csv", "r");
    file_error = file_csv->read(points);

    if (file_error == iFile::FileError::FileClosed)
        std::cout << "plik zamkniety" << std::endl;

    else if (file_error == iFile::FileError::OperationNotPermitted)
        std::cout << "brak dostepu do pliku" << std::endl;

    else if (file_error == iFile::FileError::FILE_INVALID)
        std::cout << "bledny format pliku" << std::endl;

    else if (file_error == iFile::FileError::OUT_OF_BOUNDS)
        std::cout << "poza zakresem" << std::endl;

    else if (file_error == iFile::FileError::SUCCESS)
    {
        std::cout << "plik zostal odczytany" << std::endl;
        std::cout << "pkt1: " << points[0].x << "," << points[0].y << "," << points[0].z << std::endl;
        std::cout << "pkt2: " << points[1].x << "," << points[1].y << "," << points[1].z << std::endl;
        std::cout << "pkt przedost: " << points[points.size() - 2].x << "," << points[points.size() - 2].y << "," << points[points.size() - 2].z << std::endl;
        std::cout << "pkt ost: " << points[points.size() -1].x << "," << points[points.size() -1].y << "," << points[points.size() -1].z << std::endl;
    }

    delete file_csv;



    std::cout << std::endl;
    iFile* file_csv2 = FileFactory::OpenFile("test2.csv", "w");
    file_error = file_csv2->write(points);

    if (file_error == iFile::FileError::FileClosed)
        std::cout << "plik zamkniety" << std::endl;

    else if (file_error == iFile::FileError::OperationNotPermitted)
        std::cout << "brak dostepu do pliku" << std::endl;

    else if (file_error == iFile::FileError::FILE_INVALID)
        std::cout << "bledny format pliku" << std::endl;

    else if (file_error == iFile::FileError::OUT_OF_BOUNDS)
        std::cout << "poza zakresem" << std::endl;

    else if (file_error == iFile::FileError::SUCCESS)
        std::cout << "dane zostaly zapisane do pliku" << std::endl;

    delete file_csv2;



    std::cout << std::endl;
    iFile* file_csv4 = FileFactory::OpenFile("test.csv", "r");
    file_error = file_csv4->read(point, 100000);

    if (file_error == iFile::FileError::FileClosed)
        std::cout << "plik zamkniety" << std::endl;

    else if (file_error == iFile::FileError::OperationNotPermitted)
        std::cout << "brak dostepu do pliku" << std::endl;

    else if (file_error == iFile::FileError::FILE_INVALID)
        std::cout << "bledny format pliku" << std::endl;

    else if (file_error == iFile::FileError::OUT_OF_BOUNDS)
        std::cout << "poza zakresem" << std::endl;

    else if (file_error == iFile::FileError::SUCCESS)
    {
        std::cout << "punkt zostal odczytany" << std::endl;
        std::cout << "odczytany pkt: " << point.x << "," << point.y << "," << point.z << std::endl;
    }

    delete file_csv4;




    point.x += 1;   point.y -= 1;   point.z -= 1;
    points.push_back(point);

    std::cout << std::endl;
    iFile* file_csv3 = FileFactory::OpenFile("test3.csv", "w");
    file_error = file_csv3->write(points);

    if (file_error == iFile::FileError::FileClosed)
        std::cout << "plik zamkniety" << std::endl;

    else if (file_error == iFile::FileError::OperationNotPermitted)
        std::cout << "brak dostepu do pliku" << std::endl;

    else if (file_error == iFile::FileError::FILE_INVALID)
        std::cout << "bledny format pliku" << std::endl;

    else if (file_error == iFile::FileError::OUT_OF_BOUNDS)
        std::cout << "poza zakresem" << std::endl;

    else if (file_error == iFile::FileError::SUCCESS)
        std::cout << "dane zostaly zapisane do pliku" << std::endl;

    delete file_csv3;



    std::cout << std::endl;
    iFile* file_bin = FileFactory::OpenFile("test.bin", "rb");
    file_error = file_bin->read(points);

    if (file_error == iFile::FileError::FileClosed)
        std::cout << "plik zamkniety" << std::endl;

    else if (file_error == iFile::FileError::OperationNotPermitted)
        std::cout << "brak dostepu do pliku" << std::endl;

    else if (file_error == iFile::FileError::FILE_INVALID)
        std::cout << "bledny format pliku" << std::endl;

    else if (file_error == iFile::FileError::OUT_OF_BOUNDS)
        std::cout << "poza zakresem" << std::endl;

    else if (file_error == iFile::FileError::SUCCESS)
    {
        std::cout << "plik zostal odczytany" << std::endl;
        std::cout << "pkt1: " << points[0].x << "," << points[0].y << "," << points[0].z << std::endl;
        std::cout << "pkt2: " << points[1].x << "," << points[1].y << "," << points[1].z << std::endl;
        std::cout << "pkt przedost: " << points[points.size() - 2].x << "," << points[points.size() - 2].y << "," << points[points.size() - 2].z << std::endl;
        std::cout << "pkt ost: " << points[points.size() -1].x << "," << points[points.size() -1].y << "," << points[points.size() -1].z << std::endl;

    }
    delete file_bin;



    std::cout << std::endl;
    iFile* file_bin2 = FileFactory::OpenFile("test2.bin", "wb");
    file_error = file_bin2->write(points);

    if (file_error == iFile::FileError::FileClosed)
        std::cout << "plik zamkniety" << std::endl;

    else if (file_error == iFile::FileError::OperationNotPermitted)
        std::cout << "brak dostepu do pliku" << std::endl;

    else if (file_error == iFile::FileError::FILE_INVALID)
        std::cout << "bledny format pliku" << std::endl;
    
    else if (file_error == iFile::FileError::OUT_OF_BOUNDS)
        std::cout << "poza zakresem" << std::endl;

    else if (file_error == iFile::FileError::SUCCESS)
        std::cout << "dane zostaly zapisane do pliku" << std::endl;
   
    delete file_bin2;


    system("pause");
    return 0;
}
