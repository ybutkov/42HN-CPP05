#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>


namespace {
	inline constexpr int AMOUNT_FORMS = 3;

	const std::string formNames[AMOUNT_FORMS] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*creators[])(const std::string&) = {
        [](const std::string& target)
				-> AForm* { return new ShrubberyCreationForm(target); },
        [](const std::string& target)
				-> AForm* { return new RobotomyRequestForm(target); },
        [](const std::string& target)
				-> AForm* { return new PresidentialPardonForm(target); }
    };
}


AForm* Intern::makeForm(const std::string& form, const std::string& target)
{
	std::cout << "--Intern started creation form: "
		<< form << " for target: " << target << "\n";
	for (int i = 0; i < AMOUNT_FORMS; ++i)
	{
		if (form == formNames[i])
		{
			std::cout << "--Intern creates " << form << std::endl;
			return creators[i](target);
		}
	}
	std::cout << "--Intern didnt find form: " << form << std::endl;
	throw NotFoundFormException();
	// return nullptr;	
}
