#include <iostream>
#include <fstream>
#include <string>

std::string	outName(std::string str)
{

	std::string newStr(str);

	for (int i = 0; newStr[i]; i++)
		newStr[i] -= ((newStr[i] >= 'a' && newStr[i] <= 'z') ? 32 : 0);
	newStr += ".replace";
	return newStr;
}

void	freplace(std::ifstream& file, std::ofstream& out, const std::string& s1, const std::string& s2)
{

	std::string	newStr;
	size_t		i;

	while (std::getline(file, newStr))
    {
		i = 0;
		while ((i = newStr.find(s1, i)) != std::string::npos)
        {
			newStr.erase(i, s1.size());
			newStr.insert(i, s2);
			i += s2.size();
		}
		out << newStr << "\n";
	}
}

int		main( int ac, char **av )
{
	if (ac != 4) 
    {
		std::cout << "Wrong number of argument !\n";
		return 0;
	}
	if (!av[2][0] || !av[3][0])
    {
                std::cout << "Empty string !\n";
                return 0;
    }
	std::ifstream	file(av[1]);
	if (!file.is_open())
    {
		std::cout << "Fail to open input file\n";
		return 0;
	}
	std::ofstream	out(outName(av[1]));
	if (!out.is_open())
    {
		std::cout << "Fail to open output file\n";
		return 0;
	}
	freplace(file, out, av[2], av[3]);
	file.close();
	out.close();

	return 0;
}
