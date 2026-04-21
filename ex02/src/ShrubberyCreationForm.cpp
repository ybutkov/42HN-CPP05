#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	return *this;
}

void ShrubberyCreationForm::executeForm() const
{
	std::cout << "--ShrubberyCreationForm execution started:" << std::endl;
	std::string fileName = this->getTarget() + "_shrubbery";
	std::ofstream outputFile(fileName.c_str());
	if (!outputFile.is_open())
	{
		throw std::runtime_error("ShrubberyCreationForm: cannot open/create output file: " + fileName);
	}
	
	std::string tree =
		"           ccee88oo\n"
		"        C8O8O8Q8PoOb o8oo\n"
		"      dOB69QO8PdUOpugoO9bD\n"
		"     CgggbU8OU qOp qOdoUOdcb\n"
		"         6OuU  /p u gcoUodpP\n"
		"           \\\\   /douUP\n"
		"             \\ ////\n"
		"              |||||\n"
		"              |||||\n";

   if (!(outputFile << tree))
   {
		throw std::runtime_error("ShrubberyCreationForm: failed to write to file: " + fileName);
   }

	std::cout << "--ShrubberyCreationForm execution stopped" << std::endl;
}
