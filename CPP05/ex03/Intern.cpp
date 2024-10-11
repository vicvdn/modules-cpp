/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-08 08:59:30 by vvaudain          #+#    #+#             */
/*   Updated: 2024-10-08 08:59:30 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &rhs)
{
    (void)rhs;
    return (*this);
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return ("Intern could not create Form, because it does not exist.");
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string formNames[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    int index = -1;

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            index = i;
            break;
        }
    }
    switch (index)
    {
        case 0:
            std::cout << "Intern creates " << formName << std::endl;
            return (new PresidentialPardonForm(target));
        case 1:
            std::cout << "Intern creates " << formName << std::endl;
            return (new RobotomyRequestForm(target));
        case 2:
            std::cout << "Intern creates " << formName << std::endl;
            return (new ShrubberyCreationForm(target));
        default:
            throw Intern::FormNotFoundException();
            return (NULL);
    }
}