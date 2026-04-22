#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
    static constexpr int DEFAULT_SIGN_GRADE = 25;
    static constexpr int DEFAULT_EXECUTE_GRADE = 5;
    PresidentialPardonForm() = delete;
public:
    PresidentialPardonForm(const std::string& target):
        AForm("PresidentialPardonForm", target, DEFAULT_SIGN_GRADE, DEFAULT_EXECUTE_GRADE) {}
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm() {}
protected:
    void executeForm(void) const override;
};

#endif
