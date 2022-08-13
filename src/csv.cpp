#include <iostream>
#include <fstream>
#include <vector>

#include "transaction.h"
#include "csv.h"

void read_csv(std::string filename)
{
    std::string line;
    std::string delimiter = ";";
    std::ifstream dataFile(filename);
    std::vector<transaction> transactions;

    if (!dataFile.is_open())
    {
        std::cout << "File failed to open" << std::endl;
        // TODO: Throw Exception
        return;
    }
    std::cout << "File is open" << std::endl
              << std::endl;

    // skip line with table headings
    std::getline(dataFile, line);

    while (std::getline(dataFile, line))
    {
        std::string token;

        token = get_next_token(line, delimiter);
        std::cout << token << std::endl;

        token = get_next_token(line, delimiter);
        std::cout << token << std::endl;

        token = get_next_token(line, delimiter);
        std::cout << token << std::endl;

        token = get_next_token(line, delimiter);
        std::cout << token << std::endl;

        token = get_next_token(line, delimiter);
        std::cout << token << std::endl;

        break;
    }

    dataFile.close();
}

std::string get_next_token(std::string &line, std::string delimiter)
{
    int pos = line.find(delimiter);
    std::string token = line.substr(0, pos);
    line.erase(0, pos + delimiter.length());

    return token;
}