/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:46:24 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/25 15:16:32 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

float getValueFromCsv(Input in, float value, std::map<Input, float> csvMap)
{
    for (std::map<Input, float>::iterator it = csvMap.begin(); it != csvMap.end(); it++)
    {
        if (it->first.year == in.year)
        {
            if (it->first.month == in.month)
            {
                if (it->first.day == in.day)
                    return it->second;
                if (it->first.day > in.day)
                {
                    if (it == csvMap.begin())
                        return value;
                    it--;
                    return it->second;
                }
            }
            if (it->first.month > in.month)
            {
                if (it == csvMap.begin())
                    return value;
                it--;
                return it->second;
            }
        }
        if (it->first.year > in.year)
        {
            if (it == csvMap.begin())
                return value;
            it--;
            return it->second;
        }
    }
    return -1;
}

static Input initInput(std::string date, int year, int month, int day, float value, int status)
{
    Input in;
    in.date = date;
    in.year = year;
    in.month = month;
    in.day = day;
    in.value = value;
    in.status = status;
    return in;
}

std::map<Input, float> getCsvMap()
{
    std::map<Input, float> csvMap;
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("Could not open file");
    std::string line;
    while (std::getline(file, line))
    {
        Input csv = initInput("", 0, 0, 0, 0, OK);
        if (line == "date,exchange_rate")
            continue;
        std::string date = line.substr(0, line.find(","));
        csv.status = checkDate(date);
        std::stringstream ss;
        std::string tmp = line.substr(line.find(",") + 1);
        if (csv.status != BAD_INPUT)
        {
           csv.status = checkTmp(tmp);
           if (csv.status != BAD_INPUT)
           {
                float value;
                ss << tmp;
                ss >> value;
                checkValue(value);
                if (csv.status == OK)
                {
                    csv = initInput(date, getYear(date), getMonth(date), getDay(date), value, OK);
                    csvMap[csv] = value;
                }
           }
        }
        if (csv.status == BAD_INPUT)
        {
            csvMap[csv] = -1;
            continue;
        }
    }
    return csvMap;
}

void handleExceptions(Input in, std::string line)
{
    if (in.status == NEGATIVE_VALUE)
    {
        std::cout << "Error: not a positive number." << std::endl;
    }
    if (in.status == TOO_LARGE)
    {
        std::cout << "Error: too large a number." << std::endl;
    }
    if (in.status == BAD_INPUT)
    {
        std::cout << "Error: Bad input => " << line << std::endl;
    }
}

bool checkFloatOverflow(std::string tmp)
{
    if (tmp.length() > 10)
        return true;
    double d;
    std::stringstream ss;
    ss << tmp;
    ss >> d;
    if (d > std::numeric_limits<float>::max())
        return true;
    return false;
}

std::map<Input, float> parseInfile(char *filename)
{
    std::map<Input, float> input;
    std::map<Input, float> csvMap = getCsvMap();
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Could not open file");
    
    std::string line;
    while (std::getline(file, line))
    {
        Input in = initInput("", 0, 0, 0, 0, OK);
        std::string date = line.substr(0, line.find("|"));
        in.status = checkDate(date);
        std::stringstream ss;
        std::string tmp = line.substr(line.find("|") + 1);
        if (in.status != BAD_INPUT)
        {
           in.status = checkTmp(tmp);
           if (in.status != BAD_INPUT)
           {
                if (checkFloatOverflow(tmp))
                {
                    in.status = TOO_LARGE;
                    handleExceptions(in, line);
                    continue;
                }
                float value;
                ss << tmp;
                ss >> value;
                checkValue(value);
                if (in.status == OK)
                {
                    in = initInput(date, getYear(date), getMonth(date), getDay(date), value, OK);
                    input[in] = getValueFromCsv(in, value, csvMap);
                    std::cout << in.date << " => " << in.value << " = " << input[in] * in.value << std::endl;
                    continue;
                }
           }
        }
        if (in.status == BAD_INPUT || in.status == NEGATIVE_VALUE || in.status == TOO_LARGE)
        {
            handleExceptions(in, line);
            continue;
        }
    }
    file.close();
    return input;
}

int checkDate(std::string date)
{
    while (date[date.length() - 1] == ' ')
        date = date.substr(0, date.length() - 1);
    while (date[0] == ' ')
        date = date.substr(1);
    if (date == "date")
        return HEADER;
    if (date.length() != 10)
        return BAD_INPUT;
    if (date[4] != '-' || date[7] != '-')
        return BAD_INPUT;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return BAD_INPUT;
    }
    return OK;
}

int checkTmp(std::string tmp)
{
    if (tmp.empty())
        return BAD_INPUT;
    while (tmp[0] == ' ')
        tmp = tmp.substr(1);
    while (tmp[tmp.length() - 1] == ' ')
        tmp = tmp.substr(0, tmp.length() - 1);
    if (tmp == "value" || tmp == "exchange_rate")
        return HEADER;
    for (size_t i = 0; i < tmp.length(); i++)
    {
        if (tmp[i] < '0' || tmp[i] > '9')
        {
            if (tmp[i] == '.')
                continue;
            return BAD_INPUT;
        }
    }
    return OK;
}

int checkValue(float value)
{
    if (value < 0)
        return NEGATIVE_VALUE;
    if (value > 1000)
        return TOO_LARGE;
    return OK;
}

int getYear(std::string date)
{
    std::stringstream ss;
    ss << date.substr(0, 4);
    int year;
    ss >> year;
    return year;
}

int getMonth(std::string date)
{
    std::stringstream ss;
    ss << date.substr(5, 2);
    int month;
    ss >> month;
    return month;
}

int getDay(std::string date)
{
    std::stringstream ss;
    ss << date.substr(8, 2);
    int day;
    ss >> day;
    return day;
}