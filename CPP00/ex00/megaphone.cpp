#include <iostream>
#include <cctype>

void	ToUpper(std::string str){
	int	len = str.length();

	for(int i = 0; i < len; i++)
		str[i] = toupper(str[i]);
	std::cout << str;
}

int	main(int ac, char *av[])
{
	int	i = 1;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		while (i < ac)
		{
			ToUpper((std::string)av[i]);
			i++;
		}
	}
	return (0);
}