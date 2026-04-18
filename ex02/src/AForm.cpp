#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

AForm::AForm(const std::string& name, const std::string& target,
	int gradeToSign, int gradeToExecute):
	name(name), target(target), isSigned(false), gradeToSign(gradeToSign),
	gradeToExecute(gradeToExecute)
{
	if (gradeToSign < GrageConfig::HIGHEST_GRADE || gradeToExecute < GrageConfig::HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	if (gradeToSign > GrageConfig::LOWEST_GRADE || gradeToExecute > GrageConfig::LOWEST_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other): 
	name(other.name), target(other.target), isSigned(other.isSigned),
	gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) { }

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return *this;
}

const std::string& AForm::getName() const { return name; }

const std::string& AForm::getTarget() const { return target; }

bool AForm::getSigned() const { return isSigned; }

int AForm::getGradeToSign() const { return gradeToSign; }

int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned)
		throw NotSignedFormException();
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	executeForm();
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form " << form.getName()
		<< ", target=" << form.getTarget()
		<< ": isSigned=" << (form.getSigned() ? "true" : "false")
		<< ", gradeToSign=" << form.getGradeToSign()
		<< ", gradeToExecute=" << form.getGradeToExecute()
		<< ".";
    return os;
}
