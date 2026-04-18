#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
    ShrubberyCreationForm() = delete;
public:
    ShrubberyCreationForm(const std::string& target):
        AForm("ShrubberyCreationForm", target, 145, 137) {}
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm() {}

    void executeForm(void) const override;
};

#endif
