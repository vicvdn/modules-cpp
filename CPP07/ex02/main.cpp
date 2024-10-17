/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:11:02 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/17 16:43:26 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	Array<int> intArray(10);
	Array<float> floatArray(8);

	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = i;
	for (unsigned int i = 0; i < floatArray.size(); i++)
		floatArray[i] = i + 0.5;

	std::cout << BOLDBLUE << "intArray: " << RESET;
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	std::cout << BOLDBLUE << "floatArray: " << RESET;
	for (unsigned int i = 0; i < floatArray.size(); i++)
		std::cout << floatArray[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;


	try
	{
		std::cout << "intArray[11]: " << intArray[11] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << BOLDRED << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << "floatArray[9]: " << floatArray[9] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << BOLDRED << e.what() << RESET << std::endl;
	}

	return 0;
}