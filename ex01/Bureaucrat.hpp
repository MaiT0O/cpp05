#include <string>
#include <iostream>
#include <iomanip>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        size_t            _grade;
    
    public:
        std::string     getName()const;
        size_t          getGrade()const;
        void            upGrade();
        void            downGrade();
        void            signForm(Form& f);
        Bureaucrat(std::string const name, int grade);
        Bureaucrat& operator=(const Bureaucrat& src);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat();
        ~Bureaucrat();

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