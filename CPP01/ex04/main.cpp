/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:39:45 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/06 14:58:05 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	ft_search_and_replace(char*av[], std::string s1, std::string s2) {
	std::string		filename = (std::string) av[1];
	std::ifstream	inFile(filename.c_str());

	if (!inFile.is_open()) {
		std::cerr << "Error when trying to open " << filename << std::endl;
		return ;
	}
	else {
		std::ofstream	outFile(filename.append(".replace").c_str());

		if (!outFile.is_open()) {
			std::cerr << "Error when trying to open " << filename << std::endl;
			return ;
		}
		std::string	buf;
		std::string	line;
		size_t		pos;
		int			len1 = s1.length();
		while (std::getline(inFile, line)) {
			pos = 0;
			while ((pos = line.find(s1, pos)) != std::string::npos) {
				line.erase(pos, len1);
				line.insert(pos, s2);
				pos += s2.length();
			}
			buf.append(line + "\n");
		}
		outFile << buf;
		outFile.close();
	}
	inFile.close();
}

int	main(int ac, char *av[]){
	if (ac != 4) {
		std::cerr << "Wrong amount of arguments!" << std::endl;
		return 0;
	}
	else {
		std::string s1 = av[2];
		std::string s2 = av[3];
		
		if (s1.empty() || s2.empty()) {
			std::cerr << "You can't give empty strings" << std::endl;
			return 1;
		}
		ft_search_and_replace(av, s1, s2);
	}
	return 0;
}