#include <vector>

#include "PremiumCustomer.hpp"

void PremiumCustomer::computeBalance() {
    double balance = 0;
    for (unsigned int i = 0; i < this->m_Calls.size(); ++i) {
        balance += (double)this->m_Calls.at(i)->getDuration() / 60 * this->m_minRate;
    }
    setBalance(balance + this->m_fee);
}