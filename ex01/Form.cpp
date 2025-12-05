#include "Form.hpp"

Form::Form(void): _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const std::string name, int sign_grade, int exec_grade): _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form Constructor called for " << name <<
	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
	std::endl;
    try
    {
        if (sign_grade > 150 || exec_grade > 150)
            throw(Form::GradeTooLowException());
        else if(sign_grade < 1 || exec_grade < 1)
            throw(Form::GradeTooHighException()); 
    }
    catch(Form::GradeTooLowException &e)
	{
		std::cerr << "\033[33mFailed to create " << name << "form : " << e.what() << "\033[0m" << std::endl;
	}
    catch(Form::GradeTooHighException &e)
	{
		std::cerr << "\033[33mFailed to create " << name << "form : " << e.what() << "\033[0m" << std::endl;
	}
}

Form::Form(const Form &src): _name(src._name + "_copy"), _is_signed(false), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
	std::cout << "Form Copy constructor called to copy " << src._name << " form" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Form Assignation operator called to assignate " << src._name << " form" << std::endl;
	if (this != &src)
		_is_signed = src._is_signed;
	return *this;
}

Form::~Form()
{
	std::cout << "\033[31mAForm Deconstructor for " << this->_name << " called" << std::endl;
}

void Form::beSigned(Bureaucrat &signer)
{
    try
    {
        if ((int)signer.getGrade() > this->getSignGrade())
		    throw(Form::GradeTooLowException());
	    else if (this->getIsSigned() == false)
	    {
	    	this->_is_signed = true;
	    	std::cout << "\033[32m" << signer.getName() << " signed " << this->getName() << "\033[0m" << std::endl;
	    }
	    else
	    	std::cout << "\033[33m" << signer.getName() << " couldn’t sign " << this->getName() << " because this form is already signed\033[0m" << std::endl;
    }
    catch(Form::GradeTooLowException& e)
    {
        std::cerr << "\033[33m" << signer.getName() << " couldn’t sign " << this->getName() << " because " << e.what() << "\033[0m" << std::endl;
    }	
}

const std::string	Form::getName(void)const
{
	return (this->_name);
}

bool	Form::getIsSigned(void)const
{
	return (this->_is_signed);
}

const std::string	Form::getIsSignedStr(void)const
{
	if (this->_is_signed)
		return ("✓ true");
	else
		return ("✗ false");
}

int	Form::getSignGrade(void)const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade(void)const
{
	return (this->_exec_grade);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << a->getName() <<
	", Form signe grade " << a->getSignGrade() <<
	", exec-grade " << a->getExecGrade() <<
	", is signed : " << a->getIsSignedStr() <<
	std::endl;
	return (o);
}