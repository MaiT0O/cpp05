#include "Form.hpp"

int main()
{
    std::cout << "\n\033[35m--- TEST 1 : Création d'un formulaire valide ---\033[0m\n" << std::endl;
    Form f1("A38", 50, 25);
    std::cout << &f1;

    std::cout << "\n\033[35m--- TEST 2 : Création avec grade trop haut (exception) ---\033[0m\n" << std::endl;
    Form f2("B21", 0, 10);

    std::cout << "\n\033[35m--- TEST 3 : Création avec grade trop bas (exception) ---\033[0m\n" << std::endl;
    Form f3("C12", 151, 100);

    std::cout << "\n\033[35m--- TEST 4 : Signature par Bureaucrat ---\033[0m\n" << std::endl;
    Bureaucrat good("Alice", 40);
    Bureaucrat bad("Bob", 140);

    std::cout << "Bureaucrat Alice : " << good.getGrade() << std::endl;
    std::cout << "Bureaucrat Bob : " << bad.getGrade() << std::endl;
    good.signForm(f1);
    bad.signForm(f2);

    std::cout << "\n\033[35mTentative de signature par Bob (trop bas) :\033[0m" << std::endl;
    f1.beSigned(bad);

    std::cout << "\n\033[35mTentative de signature par Alice (OK) :\033[0m" << std::endl;
    f1.beSigned(good);

    std::cout << "\n\033[35mTentative de resigner Alice (déjà signé) :\033[0m" << std::endl;
    f1.beSigned(good);
    std::cout << "\n";

    return 0;
}
