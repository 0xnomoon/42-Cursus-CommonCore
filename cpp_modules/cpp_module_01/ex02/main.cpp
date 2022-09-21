# include <string>
# include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";

    std::string*    strptr = &str;
    std::string&    strref = str;

    std::cout << "Adress: " << &str << std::endl;
    std::cout << "Adress from stringPTR: " << strptr << std::endl;
    std::cout << "Adress from StringREF: " << &strref << std::endl;
    std::cout << "display string w pointer: " << *strptr << std::endl;
    std::cout << "display string w ref: " << strref << std::endl ;
}
