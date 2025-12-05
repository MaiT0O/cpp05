#pragma once

#include <fstream>
#include "AForm.hpp"

class AForm;

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;

        virtual void    performAction() const;
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
        ~ShrubberyCreationForm();

        class OpenFileExeption : public std::exception
	    {
		    public:
			    virtual const char *what() const throw();
	    };
};