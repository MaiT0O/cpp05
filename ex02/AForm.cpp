#include "AForm.hpp"

AForm::AForm(void): _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(const std::string name, int sign_grade, int exec_grade): _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "AForm Constructor called for " << name <<
	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
	std::endl;
    try
    {
        if (sign_grade > 150 || exec_grade > 150)
            throw(AForm::GradeTooLowException());
        else if(sign_grade < 1 || exec_grade < 1)
            throw(AForm::GradeTooHighException()); 
    }
    catch(AForm::GradeTooLowException &e)
	{
		std::cerr << "\033[33mFailed to create " << name << "form : " << e.what() << "\033[0m" << std::endl;
	}
    catch(AForm::GradeTooHighException &e)
	{
		std::cerr << "\033[33mFailed to create " << name << "form : " << e.what() << "\033[0m" << std::endl;
	}
}

AForm::AForm(const AForm &src): _name(src._name + "_copy"), _is_signed(false), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
	std::cout << "AForm Copy constructor called to copy " << src._name << " form" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "AForm Assignation operator called to assignate " << src._name << " form" << std::endl;
	if (this != &src)
		_is_signed = src._is_signed;
	return *this;
}

AForm::~AForm()
{
	std::cout << "\033[31mAForm Deconstructor for " << this->_name << " called" << std::endl;
}

void AForm::beSigned(Bureaucrat &signer)
{
    try
    {
        if ((int)signer.getGrade() > this->getSignGrade())
		    throw(AForm::GradeTooLowException());
	    else if (this->getIsSigned() == false)
	    {
	    	this->_is_signed = true;
	    	std::cout << "\033[32m" << signer.getName() << " signed " << this->getName() << "\033[0m" << std::endl;
	    }
	    else
	    	std::cout << "\033[33m" << signer.getName() << " couldn’t sign " << this->getName() << " because this form is already signed\033[0m" << std::endl;
    }
    catch(AForm::GradeTooLowException& e)
    {
        std::cerr << "\033[33m" << signer.getName() << " couldn’t sign " << this->getName() << " because " << e.what() << "\033[0m" << std::endl;
    }	
}

const std::string	AForm::getName(void)const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void)const
{
	return (this->_is_signed);
}

const std::string	AForm::getIsSignedStr(void)const
{
	if (this->_is_signed)
		return ("✓ true");
	else
		return ("✗ false");
}

int	AForm::getSignGrade(void)const
{
	return (this->_sign_grade);
}

int	AForm::getExecGrade(void)const
{
	return (this->_exec_grade);
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

const char *AForm::IsNotSignedException::what(void) const throw()
{
	return ("Form not signed");
};

void	AForm::execute(Bureaucrat const& executor)const
{
	if (this->_is_signed == false)
		throw IsNotSignedException();
	if (static_cast<size_t>(this->_exec_grade) > executor.getGrade())
		throw GradeTooLowException();

	performAction();
}

std::ostream	&operator<<(std::ostream &o, AForm *a)
{
	o << a->getName() <<
	", Form signe grade " << a->getSignGrade() <<
	", exec-grade " << a->getExecGrade() <<
	", is signed : " << a->getIsSignedStr() <<
	std::endl;
	return (o);
}