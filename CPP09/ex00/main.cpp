/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:01:58 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/24 16:00:04 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


//the operator [] allows us to insert a new element in the map if it doesn't exist
std::map<std::string, float> parseInfile(char *filename)
{
    std::map<std::string, float> input;
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Could not open file");
    
    std::string line;
    while (std::getline(file, line))
    {
        std::string date = line.substr(0, line.find("|"));
        checkDate(date);
        std::stringstream ss;
        std::string tmp = line.substr(line.find("|") + 1);
        checkTmp(tmp);
        float value;
        ss << tmp;
        ss >> value;
        checkValue(value);
        input[date] += value;
    }
    file.close();
    return input;
}

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
            std::map<std::string, float> input = parseInfile(av[1]);
            for (std::map<std::string, float>::iterator it = input.begin(); it != input.end(); it++)
                std::cout << it->first << " | " << it->second << std::endl;
            // BitcoinExchange exchange(atoi(av[1]));
            // exchange.display();
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }
    return 0;
}