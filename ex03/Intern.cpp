#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Default Intern Constructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
    *this = copy;
}

Intern& Intern::operator=(const Intern& src)
{
    (void)src;
	return (*this);
}

Intern::~Intern()
{
    std::cout << "\033[31mDefault Intern Destructor called\033[0m" << std::endl;
}

AForm* Intern::makeForm(std::string form_name, std::string form_target)
{
    int i = 0;
	std::string available_forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	while (i < 3 && form_name != available_forms[i])
		i++;

	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << form_name << std::endl;
		return (new ShrubberyCreationForm(form_target));
	case 1:
		std::cout << "Intern creates " << form_name << std::endl;
		return (new RobotomyRequestForm(form_target));
	case 2:
		std::cout << "Intern creates " << form_name << std::endl;
		return (new PresidentialPardonForm (form_target));
	default:
		std::cout << "Form is not existing" << std::endl;
		return NULL;
	}
}