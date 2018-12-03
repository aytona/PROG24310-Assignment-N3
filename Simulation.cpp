#include "Simulation.h"

Simulation::Simulation() {
    srand(time(NULL));
    
    m_numOfPremMem = rand() % 101 + 300;
    m_numOfRegMem = rand() % 101 + 300;
    
    for (int i = 1; i < m_numOfPremMem; ++i) {
        m_premCustomers.push_back(generateCustomer(true));
    }
    
    for (int i = 1; i < m_numOfRegMem; ++i) {
        m_regCustomers.push_back(generateCustomer(false));
    }
}

Simulation::~Simulation() {
    
}

void Simulation::printResult() {
    std::cout << "Simulation run:\n--------------------\n";
    std::cout << "Regular Customers:\n"
            << "\tNumber of customers in the group:\t" << m_numOfRegMem << std::endl;
    double regNumOfCalls = 0;
    double regDurOfCalls = 0;
    double regBalance = 0;
    
    
    
    std::cout << "\tAverage number of calls per customer:\t"
            << "\tAverage duration of the call per customer:\t"
            << "\tAverage balance per customer:\t"
            << "\tCustomer with largest balance:\t"
            << "\tCustomer with smallest balance:\t";
}

std::string Simulation::generateName() {
    int fnLength = rand() % 2 + 4;
    int lnLength = rand() % 2 + 4;
    std::string firstName = "";
    std::string lastName = "";
    
    for (int i = 1; i < fnLength; ++i) {
        char randChar;
        if (i == 1) {
            randChar = (char)rand() % 26 + 65;
        } else {
            randChar = (char)rand() % 26 + 97;
        }
        
        firstName.push_back(randChar);
    }
    
    for (int i = 1; i < lnLength; ++i) {
        char randChar;
        if (i == 1) {
            randChar = (char)rand() % 26 + 65;
        } else {
            randChar = (char)rand() % 26 + 97;
        }
        lastName.push_back(randChar);
    }
    
    std::string fullName = "";
    fullName.append(firstName);
    fullName.append(' ');
    fullName.append(lastName);
    return fullName;
}

std::string Simulation::generateNumber() {
    std::string number;
    for (int i = 0; i < 11; ++i) {
        if (i == 3 || i == 7) {
            number.push_back('-');
        } else {
            number.push_back((char)rand() % 10);
        }
    }
    return number;
}

double Simulation::generateDuration() {
    return (double)rand() % 721 + 20;
}

Customer Simulation::generateCustomer(bool isPrem) {
    int numberOfCalls = rand() % 250 + 1;
    if (isPrem) {
        Customer prem = new PremiumCustomer(generateName());
        for (int i = 0; i < numberOfCalls; ++i) {
            prem->addCall(generateNumber(), generateDuration());
        }
        return prem;
    } else {
        Customer reg = new RegularCustomer(generateName());
        for (int i = 0; i < numberOfCalls; ++i) {
            reg->addCall(generateNumber(), generateDuration());
        }
        return reg;
    }
}