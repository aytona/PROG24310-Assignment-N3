#pragma once

#include <string>

class Call {
public:
    Call();
    Call(std::string, uint);
    virtual ~Call();
    
    std::string getPhoneNumber();
    uint getDuration();
private:
    std::string m_phoneNumber;
    uint m_duration;
};