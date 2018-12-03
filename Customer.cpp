#include "Customer.h"

Customer::Customer() {
    this->m_name = "";
    this->m_balance = 0;
}

Customer::Customer(std::string name) {
    this->m_name = name;
	this->m_balance = 0;
}

Customer::~Customer() {
    m_Calls.clear();
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


void Customer::computeBalance()
{
	// Gets overriden by child classes
}