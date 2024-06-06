/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:39:45 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/06 11:40:14 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>


int	main(int ac, char *av[]){
	if (ac < 4 || ac > 4)
		return 0;
	else {
		std::string		filename = (std::string) av[1];
		std::ifstream	inFile(filename);

		if (!inFile.is_open()) {
			std::cerr << "Error when trying to open " << filename << std::endl;
			return 1;
		}
		else {
			
		}
		filename.close();
	}
}