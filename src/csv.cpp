#include <iostream>
#include <fstream>

void read_csv(std::string filename)
{
    std::string line;
    std::ifstream dataFile(filename);

    if (dataFile.is_open())
    {
        std::cout << "File is open" << std::endl
                  << std::endl;

        while (std::getline(dataFile, line))
        {
            std::cout << line << std::endl;
        }
    }
    else
    {
        std::cout << "File failed to open" << std::endl;
    }

    dataFile.close();
}