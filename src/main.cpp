#include <iostream>
#include "Error.hpp"
#include "Vm.hpp"


int main(int ac, char **av)
{
    try {
        abstract::Vm Syn;
        if (ac == 1) {
            return Syn.getInput();
        } else if (ac == 2) {
            return Syn.getInput(av[1]);
        } else 
            throw Too_much_arg("Too much Argument");
    }
    catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}