#pragma once

#include "Customer.hpp"

class PremiumCustomer : public Customer{
    using Customer::Customer;

public:
    void computeBalance();

private:
    const double m_fee = 30;
    const double m_minRate = 0.05;
};