/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:52:37 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/28 17:01:21 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage : ./exec list_of_numbers" << std::endl;
        return 1;
    }
    std::string str = av[1];
    parseString(str);
    PmergeMe pm(str);
    pm.print();
}