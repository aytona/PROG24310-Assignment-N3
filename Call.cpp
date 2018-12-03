#include "Call.h"

Call::Call() {
    this->m_phoneNumber = "";
    this->m_duration = 0;
}

Call::Call(std::string phoneNumber, double duration) {
    this->m_phoneNumber = phoneNumber;
    this->m_duration = duration;
}

Call::~Call() {
    
}

std::string Call::getPhoneNumber() {
    return this->m_phoneNumber;
}

double Call::getDuration() {
    return this->m_duration;
}