#include <iostream>
#include <fstream>

void read_csv()
{
    std::string line;
    std::ifstream dataFile("Statements_Midata_01-08-22_07-08-22.csv");

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