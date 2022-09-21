#include <string>
#include <locale>
#include <iostream>

using namespace std;

int	main(int ac, char const *argv[])
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
	else
	{
		for (int k = 1; k < ac; k++)
		{
			std::string str(argv[k]);
			for (size_t y = 0; y < str.length(); y++)
				std::cout << (char)std::toupper(str[y]);
		}
		std::cout << std::endl;
	}
	return (0);
}