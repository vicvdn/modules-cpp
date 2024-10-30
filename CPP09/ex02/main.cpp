/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:52:37 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/30 11:30:06 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool parseString(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ' && str[i] != '\t' && (str[i] < '0' || str[i] > '9'))
        {
            std::cout << "Error: Invalid character in string" << std::endl;
            return false;
        }
    }
    return true;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage : ./exec list_of_numbers" << std::endl;
        return 1;
    }
    std::string str = av[1];
    if (parseString(str) == false)
        return 1;
    std::cout << "Before : " << str << std::endl;
    try
    {
        PmergeMeVector vec(str);
        vec.handleVector();
        // PmergeMeDeque deq(str);
        // pm.handleDeque();
        // pm.print();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}