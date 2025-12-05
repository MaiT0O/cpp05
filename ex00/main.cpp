#include "Bureaucrat.hpp"

int   main()
{
    std::cout << "\033[32mConstructing\033[0m" << std::endl;
	Bureaucrat *a = new Bureaucrat();
    Bureaucrat *b = new Bureaucrat("michel", 200);
    Bureaucrat *c = new Bureaucrat("payou", 0);
    Bureaucrat *d = new Bureaucrat("martin", 75);
    Bureaucrat *e = new Bureaucrat("Gus", 1);
	std::cout << std::endl;
    
    std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << a;
    std::cout << b;
    std::cout << c;
    std::cout << d;
    std::cout << e;

    a->downGrade();
    c->upGrade();
    d->upGrade();
    e->upGrade();

    std::cout << std::endl;
    std::cout << "\033[31mDesstructing\033[0m" << std::endl;
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
}