#include "Bureaucrat.hpp"
#include <iostream>

namespace {

void testBureaucrat(std::string name, int grade)
{
	try
	{
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat << std::endl;	
	
	}
	catch(const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}	
}

}

int main()
{
	testBureaucrat("Bob", 10);
	testBureaucrat("John", 200);
	testBureaucrat("Karl", -1);

	try {
		Bureaucrat bob("Bob", 2);
		std::cout << "Created: " << bob << std::endl;
		bob.upGrade();
		std::cout << "After 1st upGrade: " << bob << std::endl;
		bob.upGrade();
		std::cout << "After 2nd upGrade: " << bob << std::endl;
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}

	try {
		Bureaucrat john("John", 149);
		std::cout << "Created: " << john << std::endl;
		john.downGrade();
		std::cout << "After 1st downGrade: " << john << std::endl;
		john.downGrade();
		std::cout << "After 2nd downGrade: " << john << std::endl;
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}

	return 0;
}
