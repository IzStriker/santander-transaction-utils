#pragma once
#include <string>
#include <ctime>

struct transaction
{
    struct tm date;
    std::string paymentType;
    std::string merchantDescription;
    int amount;
    int balance;
};