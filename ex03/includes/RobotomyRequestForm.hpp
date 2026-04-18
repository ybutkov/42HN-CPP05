#ifndef ROBOTO_MY_REQUEST_FORM_HPP
# define ROBOTO_MY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
    RobotomyRequestForm() = delete;
public:
    RobotomyRequestForm(const std::string& target):
        AForm("RobotomyRequestForm", target, 72, 45) {}
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm() {}

    void executeForm(void) const override;
};

#endif
