#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
	AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	AForm::operator=(other);
	return *this;
}

void PresidentialPardonForm::executeForm() const
{
	std::cout << "--PresidentialPardonForm execution started:\n";
	std::cout << "----We inform you that " << this->getTarget() 
		<< " has been pardoned by Zaphod Beeblebrox\n";
	std::cout << "--PresidentialPardonForm execution stopped" << std::endl;
}
