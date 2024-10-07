/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:28:04 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/07 09:16:06 by vvaudain         ###   ########.fr       */
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
	printHeader("Creating forms ");	
	try
	{
		Bureaucrat	b1("chief", 1);
		Bureaucrat	b2("semi chief", 45);
		Bureaucrat	b3("not chief", 150);

		// Form	f1("form1", 1, 0); //will throw grade is too high exception
		// Form	f2("form2", 0, 1); //will throw grade is too high exception
		// Form	f3("form3", 151, 151); //will throw grade is too low exception
		Form	f4("form4", 1, 1);
		Form	f5("form5", 45, 45);

		printHeader("Attempting to sign forms");
		b1.signForm(f4);
		b1.signForm(f5);
		b2.signForm(f5);
		printHeader("Attempting to sign forms with bureaucrats of too low grade");
		b2.signForm(f4); //will throw exception
		b3.signForm(f5); //will throw exception
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << e.what() << RESET << std::endl;
	}
	return (0);
}