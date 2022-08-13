#pragma once
#include <iostream>
#include "transaction.h"

void read_csv(std::string, std::vector<transaction> &);

std::string get_next_token(std::string &, std::string);