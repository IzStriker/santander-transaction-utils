#include <iostream>
#include <string>

#include "csv.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Error: Missing required argument filename" << std::endl;
        std::cout << "\t e.g. ./main data.csv" << std::endl;
        return 1;
    }

    read_csv(argv[1]);

    return 0;
}
