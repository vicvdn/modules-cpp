/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:18:15 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/07 22:51:33 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void printHeader(std::string str)
{
	std::cout << std::endl;
	std::cout << BLUE << "----------------" << str << "----------------" << RESET << std::endl;
	std::cout << std::endl;
}


int main(void)
{
	try
	{
		Bureaucrat b1("Victoire", 1);
		Intern intern;
		AForm *form1;
		AForm *form2;
		AForm *form3;

		form1 = intern.makeForm("RobotomyRequestForm", "Victoire");
		printHeader("Bureaucrat signs form1");
		b1.signForm(*form1);
		printHeader("Bureaucrat executes form1");
		b1.executeForm(*form1);

		form2 = intern.makeForm("ShrubberyCreationForm", "Victoire");
		printHeader("Bureaucrat signs form2");
		b1.signForm(*form2);
		printHeader("Bureaucrat executes form2");
		b1.executeForm(*form2);
		
		form3 = intern.makeForm("PresidentialPardonForm", "Victoire");
		printHeader("Bureaucrat signs form3");
		b1.signForm(*form3);
		printHeader("Bureaucrat executes form3");
		b1.executeForm(*form3);

		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}