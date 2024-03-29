#pragma once

#include <string>
#include <cmath>

class Call {
public:
    Call();
    Call(std::string, double);
    virtual ~Call();
    
    std::string getPhoneNumber();
    double getDuration();
private:
    std::string m_phoneNumber;
    double m_duration;
};