#pragma once

#include <string>
#include <vector>

#include "Call.h"

class Customer {
public:
    Customer();
    Customer(std::string, double);
    ~Customer();
    
    void setName(std::string);
    std::string getName();
    void addCall(uint, uint);
    double getBalance();
    void setBalance(double);
    
    virtual void computeBalance();
    
protected:
    std::string m_name;
    std::vector<*Call> m_Calls;
    double m_balance;
};