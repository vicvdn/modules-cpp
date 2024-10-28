/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:33:29 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/28 15:37:35 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : str("") {}

RPN::RPN(std::string str) : str(str) {
}

RPN::RPN(const RPN &src) : str(src.str) {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
    {
        str = rhs.str;
    }
    return *this;
}

static bool isOp(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::compute(void){
    
    int operand1, operand2, result;
    int strlen = str.length();
    std::stack<int> stack;

    for (int i = 0; i < strlen; i++)
    {
        char c = str[i];
        if (c == ' ')
            continue;
        
        if (c >= '0' && c <= '9')
            stack.push(c - '0');
        
        else if (isOp(c)) 
        {
            if (stack.size() < 2) {
                std::cerr << "Invalid expression: not enough operands for operator " << c << std::endl;
                return;
            }
            operand2 = stack.top();
            stack.pop();
            operand1 = stack.top();
            stack.pop();
            switch (c) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/':
                    if (operand2 == 0) {
                        std::cerr << "Division by zero" << std::endl;
                        return;
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    std::cerr << "Invalid operator: " << c << std::endl;
                    return;
            }
            stack.push(result);
        } 
        else 
        {
            std::cerr << "Error" << std::endl;
            return;
        }
    }
    if (stack.size() != 1) {
        std::cerr << "Invalid expression: not a valid RPN" << std::endl;
        return;
    }
    std::cout << "Result: " << stack.top() << std::endl;
}
