#include "Call.h"

Call::Call() {
    m_phoneNumber = "";
    m_duration = 0;
}

Call::Call(std::string phoneNumber, uint duration) {
    m_phoneNumber = phoneNumber;
    m_duration = duration;
}

Call::~Call() {
    
}

std::string Call::getPhoneNumber() {
    return m_phoneNumber;
}

uint Call::getDuration() {
    return m_duration;
}