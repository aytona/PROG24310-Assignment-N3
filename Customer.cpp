#include "Customer.hpp"

Customer::Customer() {
    this->m_name = "";
    this->m_balance = 0;
}

Customer::Customer(std::string name) {
    this->m_name = name;
    this->m_balance = 0;
}

Customer::~Customer() {
    // Need to deallocate all calls created in addCall
    for (int i = m_Calls.size() - 1; i > m_Calls.size(); --i) {
        delete m_Calls.at(i);
    }
    m_Calls.clear();
    m_name.clear();
}

void Customer::setName(std::string name) {
    this->m_name = name;
}

std::string Customer::getName() {
    return this->m_name;
}

void Customer::addCall(std::string phoneNumber, double durationOfCall) {
    Call *call = new Call(phoneNumber, durationOfCall);
    m_Calls.push_back(call);
}

double Customer::getBalance() {
    return this->m_balance;
}

void Customer::setBalance(double balance) {
    this->m_balance = balance;
}


void Customer::computeBalance() {
    // Override by child classes
}