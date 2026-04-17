#include "Bureaucrat.hpp"
#include "Form.hpp"
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

void Bureaucrat::signForm(Form& form)
{
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const GradeException& ex) {
		std::cout << this->getName() << " couldn't sign " << form.getName() 
			<< " because " << ex.what() << std::endl;
	}

}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}
