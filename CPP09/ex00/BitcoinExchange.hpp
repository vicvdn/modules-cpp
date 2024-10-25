/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:02:19 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/25 15:12:32 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <map>
#include <fstream>
#include <sstream>
#include <limits>

enum Error
{
    HEADER,
    BAD_INPUT,
    NEGATIVE_VALUE,
    TOO_LARGE,
    OK
};

struct Input
{
    std::string date;
    int year;
    int month;
    int day;
    float value;
    int status;

    bool operator<(const Input& other) const {
        if (date != other.date) return date < other.date;
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        if (day != other.day) return day < other.day;
        return value < other.value;
    }
};

std::map<Input, float> parseInfile(char *filename);
int checkDate(std::string date);
int checkTmp(std::string tmp);
int checkValue(float value);
int getYear(std::string date);
int getMonth(std::string date);
int getDay(std::string date);

#endif