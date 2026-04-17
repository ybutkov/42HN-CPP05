#include "Bureaucrat.hpp"
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

unsigned int  Bureaucrat::getGrade() const { return grade; }

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}
