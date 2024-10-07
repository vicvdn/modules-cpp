/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:14:29 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/07 22:50:17 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	this->target = other.target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return (*this);
	this->target = other.target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::setTarget(std::string target)
{
	this->target = target;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (target);
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &rhs)
{
	out << YELLOW << "PresidentialPardonForm " << rhs.getName() << " is ";
	if (rhs.getIsSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << rhs.getGradeToSign() << " to be signed and grade " << rhs.getGradeToExecute() << " to be executed" << RESET;
	return (out);
}