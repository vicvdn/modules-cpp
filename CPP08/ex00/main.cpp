/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:45:48 by victoirevau       #+#    #+#             */
/*   Updated: 2024/11/05 16:58:28 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
	std::cout << BOLDBLUE << "Testing with a vector of int from 0 to 9" << RESET << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	try
	{
		std::cout << BOLDGREEN << easyfind(vec, 5) << RESET << std::endl;
		std::cout << BOLDBLUE << easyfind(vec, 9) << RESET << std::endl;
		std::cout << BOLDGREEN << easyfind(vec, 42) << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BOLDRED << e.what() << RESET << std::endl;
	}

	std::cout << BOLDBLUE << "Testing with a list of int from 0 to 9" << RESET << std::endl;
	std::list<int> lst;
	for (int i = 0; i < 10; i++)
		lst.push_back(i);

	try
	{
		std::cout << BOLDGREEN << easyfind(lst, 5) << RESET << std::endl;
		std::cout << BOLDGREEN << easyfind(lst, 42) << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BOLDRED << e.what() << RESET << std::endl;
	}
	
	return 0;
}