#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string_view>

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	if (grade < GrageConfig::HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > GrageConfig::LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) { }


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		// Not good!
		// const_cast<std::string&>(name) = other.name;
		grade = other.grade;
	}
	return *this;
}

const std::string& Bureaucrat::getName() const { return name; }

int  Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::upGrade()
{
	if (grade == GrageConfig::HIGHEST_GRADE)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::downGrade()
{
	if (grade == GrageConfig::LOWEST_GRADE)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(AForm& form)
{
	try {
		form.beSigned(*this);
		std::cout << "Bureaucrat " << this->getName() 
			<< " signed " << form.getName() << std::endl;
	}
	catch (const GradeException& ex) {
		std::cout << this->getName() << " couldn't sign " << form.getName() 
			<< ". Error: " << ex.what() << std::endl;
	}

}

void Bureaucrat::executeForm(AForm const & form) const
{
	try {
		form.execute(*this);
		std::cout << "Bureaucrat " << this->getName() << " executed " << form.getName() 
			<< " successfully" << std::endl;
	}
	catch (const AForm::NotSignedFormException& ex) {
		std::cout << this->getName() << " couldn't execute " << form.getName() 
			<< ". Error: " << ex.what() << std::endl;
	}
	catch (const AForm::GradeTooLowException ex) {
		std::cout << this->getName() << " couldn't execute " << form.getName() 
			<< ". Error: " << ex.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << "Bureaucrat " << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}
