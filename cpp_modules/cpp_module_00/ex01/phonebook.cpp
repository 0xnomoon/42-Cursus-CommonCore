#include "contact.hpp"

std::string truncate(std::string src)
{
	if (src.length() > 10)
		return src.substr(0, 9) + ".";
	return src;
}

void print_contacts(Contact contacts[8], int *index)
{
	if (*index == 0)
	{
		std::cout << "No contacts yet !" << std::endl << std::endl;
		return ;
	}
	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|" << std::setw(10) << std::left << "Index";
	std::cout << "|" << std::setw(10) << std::left << "Name";
	std::cout << "|" << std::setw(10) << std::left << "Last Name";
	std::cout << "|" << std::setw(10) << std::left << "Nickname" << "|" << std::endl;
	std::cout << " ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	for (int i = 0; i < *index; i++)
	{
		std::cout << "|" << std::setw(10) << std::left << i << "|";
		std::cout << std::setw(10) << std::left << truncate(contacts[i].get_name()) << "|";
		std::cout << std::setw(10) << std::left << truncate(contacts[i].get_lastname()) << "|";
		std::cout << std::setw(10) << std::left << truncate(contacts[i].get_nickname()) << "|";
		std::cout << std::endl;
		std::cout << " ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	}
	std::cout << std::endl;
}

void    print_info(Contact contacts[8])
{

    const char *c;
    int         i;
    std::string buf;
    
    std::cout << "Select Index\n";
    std::getline(std::cin, buf);
    if (buf.length() > 1 || (buf[0] < 48 || buf[0] > 57))
    {
        std::cout << "Index Incorrect\n";
        return ;
    }
    c = buf.c_str();
    i = std::atoi(c);
    printf("%d\n", i);
    if (i < 0 || i >= 8)
    {
        std::cout << "Index Incorrect\n";
        return ;
    }
    contacts[i].print();

}

void    add_contact(int *index, Contact contacts[8])
{
    std::string buf;
    
    if (*index >= 8)
    {
        std::cout << "Contacts list is full.\n";
        return ;
    }
    else
    {
        std::cout << "Name:\n";
        std::getline(std::cin, buf);
        contacts[*index].set_name(buf);
        std::cout << "Last Nane:\n";
        std::getline(std::cin, buf);
        contacts[*index].set_lastname(buf);
        std::cout << "Nickname:\n";
        std::getline(std::cin, buf);
        contacts[*index].set_nickname(buf);
        std::cout << "Phone Number:\n";
        std::getline(std::cin, buf);
        contacts[*index].set_phone(buf);
        std::cout << "Darkest Secret:\n";
        std::getline(std::cin, buf);
        contacts[*index].set_secret(buf);
        if (*index < 8)
        {
            (*index)++;
            std::cout << "Contact Added\n";
        }
    }
}

void    commands(int *index, Contact contacts[8])
{
    int         exit = 0;
    std::string cmd;

    while (exit == 0)
    {
        std::getline(std::cin, cmd);
        if (std::cin.eof())
            cmd = "EXIT";
        if (!cmd.compare("SEARCH"))
        {
            print_contacts(contacts, index);
            print_info(contacts);
        }
        else if (!cmd.compare("ADD"))
            add_contact(index, contacts);
        else if (!cmd.compare("EXIT"))
            exit = 1;
        else
            std::cout << "Command not found.\n";
        
    }
}