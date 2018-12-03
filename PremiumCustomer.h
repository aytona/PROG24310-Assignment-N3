#pragma once

class PremiumCustomer : public Customer{
public:
    PremiumCustomer();
    
    void computeBalance();

private:
    const double m_fee = 30;
    const double m_minRate = 0.05;
};