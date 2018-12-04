#pragma once

#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <iostream>
#include <locale>
#include <iomanip>

#include "Call.hpp"
#include "Customer.hpp"
#include "PremiumCustomer.hpp"
#include "RegularCustomer.hpp"

class Simulation {
public:
    Simulation();
    virtual ~Simulation();
    void printResult();
    
private:
    int m_numOfPremMem;
    int m_numOfRegMem;
    std::vector<Customer*> m_premCustomers;
    std::vector<Customer*> m_regCustomers;
    
    std::string generateName();
    std::string generateNumber();
    double generateDuration();
    Customer* generateCustomer(bool);
};