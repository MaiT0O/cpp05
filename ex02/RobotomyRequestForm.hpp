#pragma once

#include "AForm.hpp"

class AForm;

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

        virtual void    performAction() const;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
        ~RobotomyRequestForm();

        class RobotizationFailed : public std::exception
	    {
		    public:
			    virtual const char *what() const throw();
	    };
};