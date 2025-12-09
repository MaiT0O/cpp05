#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    public :
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& src);
        ~Intern();

        AForm* makeForm(std::string form_name, std::string form_target);
};