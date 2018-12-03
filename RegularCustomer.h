#pragma once

class RegularCustomer : public Customer {
public:
    void computeBalance();
    
private:
    const double m_fee = 5;
    const double m_callRate = 1;
};