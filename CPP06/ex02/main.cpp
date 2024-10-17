/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:06:41 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/17 11:56:36 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		std::cout << BOLDBLUE << "Test " << i << RESET << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	return 0;
}