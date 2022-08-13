#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

#include "transaction.h"
#include "csv.h"

void read_csv(std::string filename, std::vector<transaction> &transactions)
{
    std::string line;
    std::string delimiter = ";";
    std::string dateFormat = "%d/%m/%Y";
    std::ifstream dataFile(filename);

    if (!dataFile.is_open())
    {
        std::cout << "File failed to open" << std::endl;
        // TODO: Throw Exception
        return;
    }

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

        transaction.paymentType = get_next_token(line, delimiter);
        transaction.merchantDescription = get_next_token(line, delimiter);

        token = get_next_token(line, delimiter);

        // Remove £ sign from second position
        transaction.amount = std::stod(token.substr(0, 1) + token.substr(2)) * 100;

        token = get_next_token(line, delimiter);

        // Remove £ sign from second position
        transaction.balance = std::stod(token.substr(0, 1) + token.substr(2)) * 100;

        transactions.push_back(transaction);
    }
    dataFile.close();

    std::cout << "Total Transactions: " << transactions.size() << std::endl;
}

std::string get_next_token(std::string &line, std::string delimiter)
{
    int pos = line.find(delimiter);
    std::string token = line.substr(0, pos);
    line.erase(0, pos + delimiter.length());

    return token;
}