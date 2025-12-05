#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default_target")
{
    std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called, his target is " << this->_target << std::endl;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
    if (this != &src)
    {
        this->_target = src._target;
    }
    std::cout << "ShrubberyCreationForm Assignation constructor called, his target is " << this->_target << std::endl;
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target)
{
    std::cout << "ShrubberyCreationForm Copy constructor called, his target is " << this->_target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "\033[31mShrubberyCreationForm Destructor called, his target was " << this->_target << "\033[0m" << std::endl;
}

void    ShrubberyCreationForm::performAction()const
{
    std::ofstream outFile((_target + std::string("_shrubbery")).c_str());
    if (outFile)
    {
        outFile << "    /\\    \n";
		outFile << "   /  \\   \n";
		outFile << "  /    \\  \n";
		outFile << " /      \\ \n";
		outFile << "/________\\\n";
		outFile << "    ||    \n";
		outFile << "    ||    \n";
		outFile << "    ||    \n";
        outFile.close();
    }
    else
        throw ShrubberyCreationForm::OpenFileExeption();
}

const char *ShrubberyCreationForm::OpenFileExeption::what(void) const throw()
{
    return ("Could not open and write the file!");
}
