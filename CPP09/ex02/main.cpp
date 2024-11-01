/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:52:37 by vvaudain          #+#    #+#             */
/*   Updated: 2024/11/01 12:37:47 by victoirevau      ###   ########.fr       */
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
    if (ac < 2)
    {
        std::cout << "Usage : ./exec list_of_numbers" << std::endl;
        return 1;
    }
    std::string str;
    if (ac > 2)
    {
        std::stringstream ss;
        for (int i = 1; i < ac; i++)
        {
            ss << av[i];
            ss << " ";
        }
        str = ss.str();
    }
    else
        str = av[1];
    if (parseString(str) == false)
        return 1;
    try
    {
        PmergeMeVector vec(str);
        vec.parseVector();
        std::cout << BOLDRED << "Before : " << RESET;
        vec.sortFJ();
        PmergeMeDeque deq(str);
        deq.parseDeque();
        deq.sortFJ();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}