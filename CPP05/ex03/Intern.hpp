/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-08 08:59:27 by vvaudain          #+#    #+#             */
/*   Updated: 2024-10-08 08:59:27 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP


#include <iostream>
#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &other);
        ~Intern();
        Intern &operator=(const Intern &rhs);

        AForm *makeForm(std::string formName, std::string target);
};

#endif