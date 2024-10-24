/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:02:19 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/24 15:55:59 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
    private:
        int amount;
        int year;
        int month;
        int day;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
};

void checkDate(std::string date);
void checkTmp(std::string tmp);
void checkValue(float value);

#endif