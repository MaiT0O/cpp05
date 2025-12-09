#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default_target")
{
    std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm constructor called, his target is " << this->_target << std::endl;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
    if (this != &src)
    {
        this->_target = src._target;
    }
    std::cout << "PresidentialPardonForm Assignation constructor called, his target is " << this->_target << std::endl;
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy), _target(copy._target)
{
    std::cout << "PresidentialPardonForm Copy constructor called, his target is " << this->_target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "\033[31mPresidentialPardonForm Destructor called, his target was " << this->_target << "\033[0m" << std::endl;
}

void    PresidentialPardonForm::performAction()const
{
    std::cout << "Heeeeeey " << this->_target << ", be happt you have been pardoned by Zaphod Beeblebrox!" << std::endl;
}