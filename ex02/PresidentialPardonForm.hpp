#pragma once

#include "AForm.hpp"

class AForm;

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

        virtual void    performAction() const;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
        ~PresidentialPardonForm();
};