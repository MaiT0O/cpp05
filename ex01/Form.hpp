#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
		const std::string _name;
		bool              _is_signed;
		const int         _sign_grade;
		const int         _exec_grade;

	public:
		Form(void);
		Form(const std::string name, int sign_grade, int exec_grade);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();


		void beSigned(Bureaucrat &signer);
        const std::string	getIsSignedStr(void)const;
        const std::string getName(void)const;
		bool getIsSigned(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Form *a);                    