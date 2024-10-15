/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:36:12 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/14 15:41:00 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}