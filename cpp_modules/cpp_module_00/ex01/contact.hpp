#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>
# include <iomanip>

class Contact {
    public:
        Contact(void);
        ~Contact(void);
        void        set_name(std::string name);
        void        set_lastname(std::string lastname);
        void        set_nickname(std::string nickname);
        void        set_phone(std::string phone);
        void        set_secret(std::string secret);
        void        print(void);
        std::string get_name(void);
        std::string get_lastname(void);
        std::string get_nickname(void);

    private:
        std::string name;
        std::string lastname;
        std::string nickname;
        std::string phone;
        std::string secret;

};

void        commands(int *index, Contact contacts[8]);

#endif