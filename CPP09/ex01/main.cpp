/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:32:58 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/28 14:07:48 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./RPN expression" << std::endl;
        return 1;
    }
    std::string arg = av[1];
    if (arg.empty())
    {
        std::cerr << "Empty expression" << std::endl;
        return 1;
    }
    RPN rpn(av[1]);
    rpn.compute();
    return 0;
}