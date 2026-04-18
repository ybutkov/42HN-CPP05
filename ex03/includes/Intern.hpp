#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>


class Intern {
public:
    Intern() {};
    Intern(const Intern &other) { (void)other; };
    Intern& operator=(const Intern& other) { (void)other; return *this; };
    ~Intern() {}
    
	AForm* makeForm(const std::string& form, const std::string& target);

    class NotFoundFormException : public std::exception {
    public:
        const char* what() const noexcept override { return "Form for creation not found"; }
    };
};

#endif
