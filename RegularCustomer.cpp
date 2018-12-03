#include <vector>

#include "RegularCustomer.h"

void RegularCustomer::computeBalance() {
    double balance = 0;
    balance += (double)this->m_Calls.size() * m_callRate;
    setBalance(balance + m_fee);
}