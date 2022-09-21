#include "contact.hpp"

void    header(void)
{
    std::cout << "╔═╦╗───────╔╗────╔╗\n";
    std::cout << "║╬║╚╦═╦═╦╦═╣╚╦═╦═╣╠╗\n";
    std::cout << "║╔╣║║╬║║║║╩╣╬║╬║╬║═╣\n";
    std::cout << "╚╝╚╩╩═╩╩═╩═╩═╩═╩═╩╩╝\n";
}

void    print_help(void)
{
    std::cout << "Type 'ADD' to add a new contact\n";
    std::cout << "Type 'SEARCH' to see contacts and get information\n";
    std::cout << "Type 'EXIT' to exit zzzz\n";
}

int main(void)
{
    Contact contacts[8];
    int     index = 0;
    header();
    print_help();
    commands(&index, contacts);
}