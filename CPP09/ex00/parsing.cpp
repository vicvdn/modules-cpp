/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:46:24 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/24 15:57:04 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void checkDate(std::string date)
{
    while (date[date.length() - 1] == ' ')
        date = date.substr(0, date.length() - 1);
    while (date[0] == ' ')
        date = date.substr(1);
    if (date == "date")
        return;
    if (date.length() != 10)
        throw std::runtime_error("Invalid date format in input file");
    if (date[4] != '-' || date[7] != '-')
        throw std::runtime_error("Invalid date format in input file");
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            throw std::runtime_error("Invalid date format in input file");
    }
    return;
}

void checkTmp(std::string tmp)
{
    if (tmp.empty())
        throw std::runtime_error("Invalid value format in input file");
    while (tmp[0] == ' ')
        tmp = tmp.substr(1);
    while (tmp[tmp.length() - 1] == ' ')
        tmp = tmp.substr(0, tmp.length() - 1);
    if (tmp == "value")
        return;
    for (size_t i = 0; i < tmp.length(); i++)
    {
        if (tmp[i] < '0' || tmp[i] > '9')
        {
            if (tmp[i] == '.')
                continue;
            throw std::runtime_error("Invalid value format in input file");
        }
    }
}

void checkValue(float value)
{
    if (value < 0)
        throw std::runtime_error("Invalid value format in input file : too low");
    if (value > 1000)
        throw std::runtime_error("Invalid value format in input file : too high");
    return;
}