#include "Bureaucrat.hpp"

int main() {
    Bureaucrat bureaucrattt(15, "Joe");
	std::cout << bureaucrattt << std::endl;
	for(int i = 0; i < 14; ++i)
		bureaucrattt.upRank();
	std::cout << bureaucrattt << std::endl;
	bureaucrattt.upRank();
	std::cout << bureaucrattt << std::endl;
	for(int i = 0; i < 151; ++i)
		bureaucrattt.deRank();
	std::cout << bureaucrattt << std::endl;
	Bureaucrat brrrrr(151, "hhhh");
    Bureaucrat br(0, "Yeaer");
	return 0;
}