#include "AForm.hpp"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called for default with grade of " << this->_grade << std::endl;
}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        this->_grade = grade;
        std::cout << "Bureaucrat Constructor called for " << name <<
	    " with grade of " << grade << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "\033[33mConstructing " << name << " failed : " << e.what() << std::endl <<
        "Grade now set to 150" << "\033[0m" << std::endl;
        this->_grade = 150;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "\033[33mConstructing " << name << " failed : " << e.what() << std::endl <<
        "Grade now set to 150" << "\033[0m" << std::endl;
        this->_grade = 150;
    }
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this != &src)
        this->_grade = src._grade;
    return (*this);
};

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[31mBureaucrat Deconstructor for " << this->_name << " called\033[0m" << std::endl;
}

std::string Bureaucrat::getName()const
{
    return this->_name;
}

size_t  Bureaucrat::getGrade()const
{
    return this->_grade;
}

void    Bureaucrat::upGrade()
{
    try
    {
        if (_grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
        this->_grade--;
        std::cout << this->getName() << " grade after incrementation is " << this->getGrade() << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "\033[33mIncrementation of grade failed : " << e.what() << "\033[0m" << std::endl;
    }
}

void    Bureaucrat::downGrade()
{
    try
    {
        if (_grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();
        this->_grade++;
        std::cout << this->getName() << " grade after decrementation is " << this->getGrade() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "\033[33mDecrementation of grade failed : " << e.what() << "\033[0m" << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const & form)const 
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void    Bureaucrat::signForm(AForm& f)
{
    f.beSigned(*this);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << a->getName() << ", bureaucrat grade " << a->getGrade() << std::endl;
	return (o);
}