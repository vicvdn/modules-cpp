/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:07:21 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/17 12:00:51 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void)
{
	int i = rand() % 3;
	
	switch (i)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

/*if a dynnamic cast is possible, it means that the pointer 
is pointing to an object of the class, if not the dynamic
cast will return a NULL pointer*/

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << BOLDYELLOW << "A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << BOLDYELLOW <<  "B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << BOLDYELLOW << "C" << RESET << std::endl;
}

/*with a reference, if the dynamic cast is possible, it 
means that the reference is refering to an object of the 
class if not the dynamic cast will throw an exception */

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << BOLDGREEN << "A" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << BOLDGREEN << "B" << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << BOLDGREEN << "C" << RESET << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	}
}