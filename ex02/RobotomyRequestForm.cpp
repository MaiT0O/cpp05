#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default_target")
{
    std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called, his target is " << this->_target << std::endl;
};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
    if (this != &src)
    {
        this->_target = src._target;
    }
    std::cout << "RobotomyRequestForm Assignation constructor called, his target is " << this->_target << std::endl;
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy), _target(copy._target)
{
    std::cout << "RobotomyRequestForm Copy constructor called, his target is " << this->_target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "\033[31mRobotomyRequestForm Destructor called, his target was " << this->_target << "\033[0m" << std::endl;
}

void    RobotomyRequestForm::performAction()const
{
    int random_number = rand() % 2;

    if (random_number == 1)
		std::cout << "Beeep Be Be Beeeee Beeeeeeeep. " << this->_target << " has been robotomized successfully!" << std::endl; 		
	else
		throw RobotizationFailed();
}

const char *RobotomyRequestForm::RobotizationFailed::what() const throw()
{
	return ("Unfortunately robotomy failed.");
}
