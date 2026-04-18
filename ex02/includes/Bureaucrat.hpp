#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class AForm;

namespace GrageConfig{
	inline constexpr int HIGHEST_GRADE = 1;
	inline constexpr int LOWEST_GRADE = 150;
}

class GradeException: public std::exception {
	std::string msg;
public:
	GradeException() {}
	GradeException(const char* error): msg(error) {}
	const char* what() const noexcept override { return msg.c_str(); }
};

class Bureaucrat
{
	const std::string name;
	int grade;

  public:
	Bureaucrat(): Bureaucrat("Bureaucrat_without_name", GrageConfig::LOWEST_GRADE) {}
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat &other);
	virtual ~Bureaucrat(void) {};

	const std::string& getName() const;
	int getGrade() const;
	void upGrade();
	void downGrade();
	void signForm(AForm& form);
	void executeForm(AForm const & form) const;

	class GradeTooHighException: public GradeException {
	public:
		GradeTooHighException(): GradeException("Bureaucrat grade is too high") {}
	};

	class GradeTooLowException: public GradeException {
	public:
		GradeTooLowException(): GradeException("Bureaucrat grade is too low") {}
	};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
