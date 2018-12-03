#include "Simulation.h"

Simulation::Simulation() {
    srand((unsigned int)time(NULL));
    
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
            << "\tNumber of customers in the group:\t\t" << m_numOfRegMem << std::endl;
    double regNumOfCalls = 0;
    double regDurOfCalls = 0;
    double regBalance = 0;
	Customer &regLargest = *this->m_regCustomers.at(0);
	Customer &regSmallest = *this->m_regCustomers.at(m_regCustomers.size() - 1);

	for (int i = 1; i < this->m_numOfRegMem; ++i) {
		Customer currentCustomer = (Customer)*this->m_regCustomers.at(i - 1);
		regNumOfCalls += currentCustomer.m_Calls.size();
		for (unsigned int j = 0; j < currentCustomer.m_Calls.size(); ++j) {
			regDurOfCalls += currentCustomer.m_Calls.at(j)->getDuration();
		}
		regDurOfCalls /= currentCustomer.m_Calls.size();
		regBalance += currentCustomer.getBalance();

		if (regLargest.getBalance() < this->m_regCustomers.at(i - 1)->getBalance()) {
			regLargest = *this->m_regCustomers.at(i - 1);
		} else if (regSmallest.getBalance() > this->m_regCustomers.at(i - 1)->getBalance()) {
			regSmallest = *this->m_regCustomers.at(i - 1);
		}
	}

	regNumOfCalls /= this->m_numOfRegMem;
	regDurOfCalls /= this->m_numOfRegMem / 60;
	regBalance /= this->m_numOfRegMem;

	std::cout << "\tAverage number of calls per customer:\t\t" << (int)regNumOfCalls << std::endl
		<< "\tAverage duration of the call per customer:\t" << (int)regDurOfCalls << " mins" << std::endl
		<< "\tAverage balance per customer:\t\t\t$" << regBalance << std::endl
		<< "\tCustomer with largest balance:\t\t\t" << regLargest.getName() 
		<< " ($" << regLargest.getBalance() << ")" << std::endl
		<< "\tCustomer with smallest balance:\t\t\t" << regSmallest.getName() 
		<< " ($" << regSmallest.getBalance() << ")" << std::endl;

	std::cout << "Premium Customers:\n"
		<< "\tNumber of customers in the group:\t\t" << this->m_numOfPremMem << std::endl;
	double premNumOfCalls = 0;
	double premDurOfCalls = 0;
	double premBalance = 0;
	Customer &premLargest = *this->m_premCustomers.at(0);
	Customer &premSmallest = *this->m_premCustomers.at(m_premCustomers.size() - 1);

	for (int i = 1; i < this->m_numOfPremMem; ++i) {
		Customer currentCustomer = (Customer)*this->m_premCustomers.at(i - 1);
		premNumOfCalls += currentCustomer.m_Calls.size();
		for (unsigned int j = 0; j < currentCustomer.m_Calls.size(); ++j) {
			premDurOfCalls += currentCustomer.m_Calls.at(j)->getDuration();
		}
		premDurOfCalls /= currentCustomer.m_Calls.size();
		premBalance += currentCustomer.getBalance();

		if (premLargest.getBalance() < this->m_premCustomers.at(i - 1)->getBalance()) {
			premLargest = *this->m_premCustomers.at(i - 1);
		} else if (premSmallest.getBalance() > this->m_regCustomers.at(i - 1)->getBalance()) {
			premSmallest = *this->m_premCustomers.at(i - 1);
		}
	}

	premNumOfCalls /= this->m_numOfPremMem;
	premDurOfCalls /= this->m_numOfPremMem / 60;
	premBalance /= this->m_numOfPremMem;

	std::cout << "\tAverage number of calls per customer:\t\t" << (int)premNumOfCalls << std::endl
		<< "\tAverage duration of the call per customer:\t" << (int)premDurOfCalls << " mins" << std::endl
		<< "\tAverage balance per customer:\t\t\t$" << premBalance << std::endl
		<< "\tCustomer with largest balance:\t\t\t" << premLargest.getName()
		<< " ($" << premLargest.getBalance() << ")" << std::endl
		<< "\tCustomer with smallest balance:\t\t\t" << premSmallest.getName()
		<< " ($" << premSmallest.getBalance() << ")" << std::endl;
}

std::string Simulation::generateName() {
    int fnLength = rand() % 2 + 4;
    int lnLength = rand() % 2 + 4;
    std::string firstName = "";
    std::string lastName = "";
    
    for (int i = 1; i < fnLength; ++i) {
        char randChar;
        if (i == 1) {
            randChar = static_cast<char>((int)rand() % 26 + 65);
        } else {
            randChar = static_cast<char>((int)rand() % 26 + 97);
        }
        
        firstName.push_back(randChar);
    }
    
    for (int i = 1; i < lnLength; ++i) {
        char randChar;
        if (i == 1) {
			randChar = static_cast<char>((int)rand() % 26 + 65);
        } else {
			randChar = static_cast<char>((int)rand() % 26 + 97);
        }
        lastName.push_back(randChar);
    }
    
    std::string fullName = "";
    fullName.append(firstName);
    fullName.append(" ");
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
    return (double)(rand() % 721 + 20);
}

Customer* Simulation::generateCustomer(bool isPrem) {
    int numberOfCalls = rand() % 250 + 1;
    if (isPrem) {
        Customer *prem = new PremiumCustomer(generateName());
        for (int i = 0; i < numberOfCalls; ++i) {
            prem->addCall(generateNumber(), generateDuration());
        }
		prem->computeBalance();
        return prem;
    } else {
        Customer *reg = new RegularCustomer(generateName());
        for (int i = 0; i < numberOfCalls; ++i) {
            reg->addCall(generateNumber(), generateDuration());
        }
		reg->computeBalance();
        return reg;
    }
}