/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:33:29 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/25 16:38:33 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _str("") {}

RPN::RPN(std::string str) : _str(str) {
    std::deque<int> deque;

    
    
}

RPN::RPN(const RPN &src) : _str(src._str) {}

RPN::~RPN() {}

