#ifndef ROBOTO_MY_REQUEST_FORM_HPP
# define ROBOTO_MY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
    static constexpr int DEFAULT_SIGN_GRADE = 72;
    static constexpr int DEFAULT_EXECUTE_GRADE = 45;
    RobotomyRequestForm() = delete;
public:
    RobotomyRequestForm(const std::string& target):
        AForm("RobotomyRequestForm", target, DEFAULT_SIGN_GRADE, DEFAULT_EXECUTE_GRADE) {}
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm() {}
protected:
    void executeForm(void) const override;
};

#endif
