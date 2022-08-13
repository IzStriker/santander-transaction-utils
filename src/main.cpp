#include <iostream>
#include <string>
#include <vector>

#include "csv.h"
#include "transaction.h"
#include "expenditure.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Error: Missing required argument filename" << std::endl;
        std::cout << "\t e.g. ./main data.csv" << std::endl;
        return 1;
    }

    std::vector<transaction> transactions;
    read_csv(argv[1], transactions);
    print_expenditure(transactions);

    return 0;
}
