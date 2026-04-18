#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>


int main()
{
	Bureaucrat lead("Mr.Zaphod", 1);
	Bureaucrat middle("John", 75);
	Bureaucrat junior("Genry jr.", 150);
	ShrubberyCreationForm shrubberryForm("home");
	RobotomyRequestForm robotomyForm("wall-e");
	PresidentialPardonForm presidentialForm("Trump");

	std::string sep = "==================================================================";

	std::cout << "======== ShrubberyCreationForm ========" << std::endl;

	junior.signForm(shrubberryForm);
	middle.signForm(shrubberryForm);
	junior.executeForm(shrubberryForm);
	lead.executeForm(shrubberryForm);

	std::cout << "\n========= RobotomyRequestForm =========" <<  std::endl;
	junior.signForm(robotomyForm);
	middle.signForm(robotomyForm);
	lead.signForm(robotomyForm);
	junior.executeForm(robotomyForm);
	middle.executeForm(robotomyForm);
	lead.executeForm(robotomyForm);
	
	std::cout << "\n======= PresidentialPardonForm  =======" <<  std::endl;
	junior.signForm(presidentialForm);
	middle.signForm(presidentialForm);
	lead.signForm(presidentialForm);
	junior.executeForm(presidentialForm);
	middle.executeForm(presidentialForm);
	lead.executeForm(presidentialForm);
	return 0;
}
