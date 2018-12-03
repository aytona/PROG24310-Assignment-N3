#pragma once

#include "Customer.h"

class RegularCustomer : public Customer {
	using Customer::Customer;

public:
    void computeBalance();
    
private:
    const double m_fee = 5;
    const double m_callRate = 1;
};