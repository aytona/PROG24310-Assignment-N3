#include <vector>

#include "PremiumCustomer.h"

PremiumCustomer::PremiumCustomer() {
    m_name = "";
    m_balance = 0;
}

void PremiumCustomer::computeBalance() {
    double balance = 0;
    for (unsigned int i = 0; i < m_Calls.size(); ++i) {
        balance += m_Calls.at(i).getDuration() * m_minRate;
    }
    setBalance(balance + m_fee);
}