#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        size_t            _grade;
    
    public:
        Bureaucrat(std::string const name, int grade);
        Bureaucrat& operator=(const Bureaucrat& src);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat();
        ~Bureaucrat();

        void    signForm(AForm& f);
        void    executeForm(AForm const & form) const;

        std::string     getName()const;
        size_t          getGrade()const;
        void            upGrade();
        void            downGrade();

        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);