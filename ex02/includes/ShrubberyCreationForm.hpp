#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
    static constexpr int DEFAULT_SIGN_GRADE = 145;
    static constexpr int DEFAULT_EXECUTE_GRADE = 137;
    ShrubberyCreationForm() = delete;
public:
    ShrubberyCreationForm(const std::string& target):
        AForm("ShrubberyCreationForm", target, DEFAULT_SIGN_GRADE, DEFAULT_EXECUTE_GRADE) {}
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm() {}
protected:
    void executeForm(void) const override;
};

#endif
