#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>


int main()
{
	Bureaucrat bob("Bob", 1);
	Bureaucrat john("John", 75);
	Bureaucrat genry("Genry", 150);
	std::string sep = "==================================================================";

	try {
		Form high("Highest_Form", 1, 10);
		Form middle("Middle_Form", 20, 10);
		Form low("Lowest_Form", 150, 10);
		std::cout << high << std::endl;
		std::cout << middle << std::endl;
		std::cout << low << std::endl;
		std::cout << sep << std::endl << std::endl;

		john.signForm(high);
		std::cout << high << std::endl << std::endl;
		genry.signForm(high);
		std::cout << high << std::endl << std::endl;
		bob.signForm(high);
		std::cout << high << std::endl;
		std::cout << sep << std::endl << std::endl;

		john.signForm(middle);
		std::cout << middle << std::endl;
		std::cout << sep << std::endl;
		genry.signForm(middle);
		std::cout << middle << std::endl;
		std::cout << sep << std::endl;
		bob.signForm(middle);
		std::cout << middle << std::endl;
		std::cout << sep << std::endl << std::endl;

		genry.signForm(low);
		std::cout << low << std::endl;
		std::cout << sep << std::endl << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Form form("Wrong_form", 0, 20);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Form form("Wrong_form", 200, 20);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Form form("Wrong_form", 20, 0);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Form form("Wrong_form", 20, 200);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
