#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
	Intern someRandomIntern;
	AForm* shrubberryForm = someRandomIntern.makeForm("shrubbery creation", "home");
	AForm* robotomyForm = someRandomIntern.makeForm("robotomy request", "wall-e");
	AForm* presidentialForm = someRandomIntern.makeForm("presidential pardon", "Trump");
	AForm* notFoundForm;
	try 
	{
		notFoundForm = someRandomIntern.makeForm("notExistForm pardon", "Trump");
		(void)notFoundForm;
	}
	catch (Intern::NotFoundFormException& ex)
	{
		std::cerr << "Error: " << ex.what() << std::endl;
	}
	
	std::cout << "======== ShrubberyCreationForm ========" << std::endl;

	junior.signForm(*shrubberryForm);
	middle.signForm(*shrubberryForm);
	junior.executeForm(*shrubberryForm);
	lead.executeForm(*shrubberryForm);

	std::cout << "\n========= RobotomyRequestForm =========" <<  std::endl;
	junior.signForm(*robotomyForm);
	middle.signForm(*robotomyForm);
	lead.signForm(*robotomyForm);
	junior.executeForm(*robotomyForm);
	middle.executeForm(*robotomyForm);
	lead.executeForm(*robotomyForm);
	
	std::cout << "\n======= PresidentialPardonForm  =======" <<  std::endl;
	junior.signForm(*presidentialForm);
	middle.signForm(*presidentialForm);
	lead.signForm(*presidentialForm);
	junior.executeForm(*presidentialForm);
	middle.executeForm(*presidentialForm);
	lead.executeForm(*presidentialForm);

	for (AForm* form: {shrubberryForm, robotomyForm, presidentialForm})
	{
		delete form;
	}
	return 0;
}
