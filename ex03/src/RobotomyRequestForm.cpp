#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	return *this;
}

void RobotomyRequestForm::executeForm() const
{
	std::cout << "--RobotomyRequestForm execution started:" << std::endl;
	std::cout << "----I make some drilling noises: Bzzz-bzz" << std::endl;
	
	if (std::rand() % 2)
		std::cout << "----I have to inform you that " << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "----I have to inform you that " << this->getTarget() << " failed" << std::endl;
	std::cout << "--RobotomyRequestForm execution stopped" << std::endl;
}
