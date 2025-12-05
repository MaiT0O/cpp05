#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
		const std::string _name;
		bool              _is_signed;
		const int         _sign_grade;
		const int         _exec_grade;
		virtual void performAction()const = 0;

	public:
		AForm(void);
		AForm(std::string name, int sign_grade, int exec_grade);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		~AForm();

		void beSigned(Bureaucrat &signer);
		void execute(Bureaucrat const& executor)const;

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

	class IsNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, AForm *a);