#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Form::Form(std::string name, int gradeToSign, int gradeToExecute):
	name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < GrageConfig::HIGHEST_GRADE || gradeToExecute < GrageConfig::HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if (gradeToSign > GrageConfig::LOWEST_GRADE || gradeToExecute > GrageConfig::LOWEST_GRADE)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other): 
	name(other.name), isSigned(other.isSigned),
	gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) { }

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return *this;
}

const std::string& Form::getName() const { return name; }

bool Form::getSigned() const { return isSigned; }

int Form::getGradeToSign() const { return gradeToSign; }

int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName() 
		<< ": isSigned=" << (form.getSigned() ? "true" : "false")
		<< ", gradeToSign=" << form.getGradeToSign()
		<< ", gradeToExecute=" << form.getGradeToExecute()
		<< ".";
    return os;
}
