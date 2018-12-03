#include "Customer.h"

Customer::Customer() {
    m_name = "";
    m_balance = 0;
}

Customer::Customer(std::string name) {
    m_name = name;
    m_balance = 0;
}

Customer::~Customer() {
    delete[] m_name;
    m_Calls.clear();
}

void Customer::setName(std::string name) {
    m_name = name;
}

std::string Customer::getName() {
    return m_name;
}

void Customer::addCall(std::string phoneNumber, uint durationOfCall) {
    Call call = new Call(phoneNumber, durationOfCall);
    m_Calls.push_back(call);
}

double Customer::getBalance() {
    return m_balance;
}

void Customer::setBalance(double balance) {
    m_balance = balance;
}