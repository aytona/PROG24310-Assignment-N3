#pragma once

#include <string>
#include <vector>

#include "Call.h"

class Customer {
public:
    Customer();
    explicit Customer(std::string);
    ~Customer();
    
    void setName(std::string);
    std::string getName();
    void addCall(std::string, double);
    double getBalance();
    void setBalance(double);
    
    virtual void computeBalance();

	std::vector<Call*> m_Calls;
    
protected:
    std::string m_name;
    double m_balance;
};