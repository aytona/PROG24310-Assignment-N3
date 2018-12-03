#pragma once

#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <iostream>
#include <locale>

#include "Call.h"
#include "Customer.h"
#include "PremiumCustomer.h"
#include "RegularCustomer.h"

class Simulation {
public:
    Simulation();
    virtual ~Simulation();
    void printResult();
    
private:
    int m_numOfPremMem;
    int m_numOfRegMem;
    std::vector<*Customer> m_premCustomers;
    std::vector<*Customer> m_regCustomers;
    
    std::string generateName();
    std::string generateNumber();
    double generateDuration();
    Customer generateCustomer(bool);
};