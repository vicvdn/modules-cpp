/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:24:45 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/03 16:51:36 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( void ) {
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "String address:              " << &str << std::endl;
	std::cout << "Address in stringPTR:        " << stringPTR << std::endl;
	std::cout << "Adress in stringREF:         " << &stringREF << std::endl;
	std::cout << "\n";
	std::cout << "String value :               " << str << std::endl;
	std::cout << "Value in stringPTR :         " << stringPTR << std::endl;
	std::cout << "Value pointed by stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value pointed by ref :       " << stringREF << std::endl;
	
}