#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <string>

class AForm {
    const std::string name;
    const std::string target;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
protected:
    virtual void executeForm(void) const = 0;
public:
    AForm(const std::string& name, const std::string& target, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm& operator=(const AForm& other);
    virtual ~AForm() {}
    
	const std::string& getName() const;
    const std::string& getTarget() const;
	bool getSigned() const;
    int getGradeToSign() const;
	int getGradeToExecute() const;
    void beSigned(const Bureaucrat& bureaucrat);

    void execute(Bureaucrat const & executor) const;

    class GradeTooHighException : public GradeException {
    public:
        GradeTooHighException() : GradeException("Grade is too high") {}
    };

    class GradeTooLowException : public GradeException {
    public:
        GradeTooLowException() : GradeException("Grade is too low") {}
    };

    class NotSignedFormException : public std::exception {
    public:
        const char* what() const noexcept override { return "Form is not signed"; }
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
