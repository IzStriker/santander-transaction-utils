#pragma once
#include <vector>

#include "transaction.h"

void print_expenditure(std::vector<transaction>);

void format_date(std::ostream &, std::tm date);