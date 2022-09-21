#include "Karen.hpp"

int main(int ac, char **av)
{
    Karen karen;
    if (ac != 2)
        return 0;
    karen.complain(av[1]);
    return (0);
}
