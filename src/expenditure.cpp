#include <iostream>
#include <vector>
#include <iomanip>

#include "transaction.h"
#include "expenditure.h"

void print_expenditure(std::vector<transaction> transactions)
{
    int totalExpense = 0;
    for (int i = 0; i < transactions.size(); i++)
    {
        // Only include expenses
        if (transactions[i].amount > 0)
        {
            continue;
        }

        totalExpense += transactions[i].amount;
    }

    totalExpense *= -1;

    std::cout << "Total expenditure ";
    format_date(std::cout, transactions.back().date);
    std::cout << " - ";
    format_date(std::cout, transactions.front().date);
    std::cout << ": ";
    std::cout << "£" << totalExpense / 100 << "." << totalExpense % 100 << std::endl;
}

void format_date(std::ostream &cout, std::tm date)
{
    cout << std::setw(2) << std::setfill('0') << date.tm_mday;
    cout << "/" << std::setw(2) << std::setfill('0') << date.tm_mon + 1;
    cout << "/" << std::setw(4) << std::setfill('0') << date.tm_year + 1900;
}