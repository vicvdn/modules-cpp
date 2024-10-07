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
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void printHeader(std::string str)
{
	std::cout << std::endl;
	std::cout << BLUE << "----------------" << str << "----------------" << RESET << std::endl;
	std::cout << std::endl;
}


int main(void){
	
	Bureaucrat b1("Chief", 1);
	Bureaucrat b2("Not chief", 150);
	Bureaucrat b3("Semi chief", 45);
	ShrubberyCreationForm s1("randomz");
	PresidentialPardonForm p1("Prisoner");
	RobotomyRequestForm r1("TurbulentMachine");

	printHeader("Bureaucrats presented");
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	
	printHeader("Forms presented");
	std::cout << s1 << std::endl;
	std::cout << std::endl;
	std::cout << r1 << std::endl;
	std::cout << std::endl;
	std::cout << p1 << std::endl;

	printHeader("Chief signs forms");
	b1.signForm(s1);
	std::cout << std::endl;
	b1.signForm(r1);
	std::cout << std::endl;
	b1.signForm(p1);

	printHeader("Chief executes forms");
	b1.executeForm(s1);
	std::cout << std::endl;
	b1.executeForm(r1);
	std::cout << std::endl;
	b1.executeForm(p1);
	std::cout << std::endl;

	/*Is going to trigger errors everywhere*/
	printHeader("Not chief signs forms");
	b2.signForm(s1);
	std::cout << std::endl;
	b2.signForm(p1);
	std::cout << std::endl;
	b2.signForm(r1);
	
	printHeader("Not chief executes forms");
	b2.executeForm(s1);
	std::cout << std::endl;
	b2.executeForm(r1);
	std::cout << std::endl;
	b2.executeForm(p1);
	std::cout << std::endl;

	/*Can sign and execute 2/3 forms */
	printHeader("Semi chief signs forms");
	b3.signForm(s1);
	std::cout << std::endl;
	b3.signForm(r1);
	std::cout << std::endl;
	b3.signForm(p1);
	
	printHeader("Semi chief executes forms");
	b3.executeForm(s1);
	std::cout << std::endl;
	b3.executeForm(r1);
	std::cout << std::endl;
	b3.executeForm(p1);
	std::cout << std::endl;

	return 0;
}