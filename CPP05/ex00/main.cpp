/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:28:04 by victoirevau       #+#    #+#             */
/*   Updated: 2024/09/25 18:28:13 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void printHeader(std::string str)
{
	std::cout << std::endl;
	std::cout << BLUE << "----------------" << str << "----------------" << RESET << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	printHeader("Creating 3 bureaucrats");
	try
	{
		Bureaucrat	b1("chief", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << e.what() << RESET << std::endl;
	}

	try
	{
		Bureaucrat	b2("semi chief", 45);
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << e.what() << RESET << std::endl;
	}

	try
	{
		Bureaucrat	b3("not chief", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << e.what() << RESET << std::endl;

	}	

	printHeader("Changing grades");	
	try
	{
		Bureaucrat	b1("First", 5);
		Bureaucrat	b2("Second", 1);

		std::cout << "b1's name: " << b1.getName() << std::endl;
		std::cout << "b1's grade: " << b1.getGrade() << std::endl;
		std::cout << GREEN << b1 << RESET <<std::endl;
		std::cout << "b2's name: " << b2.getName() << std::endl;
		std::cout << "b2's grade: " << b2.getGrade() << std::endl;
		std::cout << GREEN << b2 << RESET <<std::endl;
		b1.decrementGrade();
		std::cout << "b1's grade after decrement: " << b1.getGrade() << std::endl;
		b2.incrementGrade();
		std::cout << "b2's grade after increment: " << b2.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << e.what() << RESET << std::endl;
	}
	return (0);
}