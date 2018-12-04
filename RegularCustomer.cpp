#include <vector>

#include "RegularCustomer.hpp"

void RegularCustomer::computeBalance() {
    double balance = 0;
    balance += (double)this->m_Calls.size() * m_callRate;
    setBalance(balance + m_fee);
}