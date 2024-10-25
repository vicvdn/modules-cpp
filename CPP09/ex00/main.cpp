/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:01:58 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/25 15:15:43 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//the operator [] allows us to insert a new element in the map if it doesn't exist


int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./bitcoin [amount]" << std::endl;
        return 1;
    }
    else
    {
        try {
            std::map<Input, float> input = parseInfile(av[1]);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }
    return 0;
}