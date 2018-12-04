#include "Call.hpp"

Call::Call() {
    this->m_phoneNumber = "";
    this->m_duration = 0;
}

Call::Call(std::string phoneNumber, double duration) {
    this->m_phoneNumber = phoneNumber;
    double mins = std::ceil(duration / 60);
    this->m_duration = mins * 60;
}

Call::~Call() {
    m_phoneNumber.clear();
}

std::string Call::getPhoneNumber() {
    return this->m_phoneNumber;
}

double Call::getDuration() {
    return this->m_duration;
}