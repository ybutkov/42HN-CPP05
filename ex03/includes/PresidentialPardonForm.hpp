#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
    PresidentialPardonForm() = delete;
public:
    PresidentialPardonForm(const std::string& target):
        AForm("PresidentialPardonForm", target, 25, 5) {}
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm() {}

    void executeForm(void) const override;
};

#endif
