#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Form {
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
public:
    Form(): Form("NoName", GrageConfig::HIGHEST_GRADE, GrageConfig::HIGHEST_GRADE) {}
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    ~Form() {}

    Form& operator=(const Form& other);
	const std::string& getName() const;
	bool getSigned() const;
    int getGradeToSign() const;
	int getGradeToExecute() const;
    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public GradeException {
    public:
        GradeTooHighException() : GradeException("Form grade is too high") {}
    };

    class GradeTooLowException : public GradeException {
    public:
        GradeTooLowException() : GradeException("Form grade is too low") {}
    };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
