#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

#include "transaction.h"
#include "csv.h"

std::vector<transaction> read_csv(std::string filename)
{
    std::string line;
    std::string delimiter = ";";
    std::string dateFormat = "%d/%m/%Y";
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
        // skip emtpy lines
        if (line.empty())
        {
            continue;
        }

        // Stop when get to overdraft info
        if (line.find("Arranged overdraft limit;") != std::string::npos)
        {
            break;
        }

        std::string token;
        struct transaction transaction;

        std::string date = get_next_token(line, delimiter);
        if (!strptime(date.c_str(), dateFormat.c_str(), &transaction.date))
        {
            std::cout << "Error: Invalid date found in csv file." << std::endl;
            return;
        }
        std::cout << transaction.date.tm_mday << "/" << transaction.date.tm_mon + 1 << "/" << transaction.date.tm_year + 1900 << std::endl;

        transaction.paymentType = get_next_token(line, delimiter);
        std::cout << transaction.paymentType << std::endl;

        transaction.merchantDescription = get_next_token(line, delimiter);
        std::cout << transaction.merchantDescription << std::endl;

        token = get_next_token(line, delimiter);

        // Remove £ sign from second position
        transaction.amount = std::stod(token.substr(0, 1) + token.substr(2)) * 100;
        std::cout << transaction.amount << std::endl;

        token = get_next_token(line, delimiter);

        // Remove £ sign from second position
        transaction.balance = std::stod(token.substr(0, 1) + token.substr(2)) * 100;
        std::cout << transaction.balance << std::endl;

        transactions.push_back(transaction);
    }

    std::cout << "Total Transactions: " << transactions.size() << std::endl;

    dataFile.close();

    return transactions;
}

std::string get_next_token(std::string &line, std::string delimiter)
{
    int pos = line.find(delimiter);
    std::string token = line.substr(0, pos);
    line.erase(0, pos + delimiter.length());

    return token;
}