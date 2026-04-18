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
	srand(time(0));
	std::string result = (rand() < 0.5) ? " has been robotomized successfully" : " failed";

	std::cout << "----I have to inform you that " << this->getTarget() << result << std::endl;
	std::cout << "--RobotomyRequestForm execution stopped" << std::endl;
}
