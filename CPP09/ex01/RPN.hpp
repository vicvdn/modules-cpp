/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:33:11 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/28 14:20:20 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
    private:
        std::string str;
    public:
        RPN();
        RPN(std::string str);
        RPN(const RPN &src);
        RPN &operator=(const RPN &rhs);
        ~RPN();
        void compute(void);
};

#endif