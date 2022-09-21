#include "contact.hpp"

Contact::Contact(void)
{}

Contact::~Contact(void)
{}

void Contact::print(void)
{
    std::cout << std::setw(15) << std::left << "name:" << this->name << std::endl;
    std::cout << std::setw(15) << std::left << "last name:" << this->lastname << std::endl;
    std::cout << std::setw(15) << std::left << "nickname:" << this->nickname << std::endl;
    std::cout << std::setw(15) << std::left << "phone:" << this->phone << std::endl;
    std::cout << std::setw(15) << std::left << "secret:" << this->secret << std::endl;
}



void Contact::set_name(std::string name)
{
    this->name = name;
}

void Contact::set_lastname(std::string lastname)
{
    this->lastname = lastname;
}

void Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}

void  Contact::set_phone(std::string phone)
{
    this->phone = phone;
}

void  Contact::set_secret(std::string secret)
{
    this->secret = secret;
}

std::string Contact::get_lastname(void)
{
    return this->lastname;
}

std::string Contact::get_name(void)
{
    return this->name;
}

std::string Contact::get_nickname(void)
{
    return this->nickname;
}