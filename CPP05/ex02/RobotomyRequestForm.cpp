/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:04:00 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/07 22:49:59 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	this->target = other.target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return (*this);
	this->target = other.target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "*brrrrrrr brrrrrr* " << std::endl;
	if (rand() % 2) //
		std::cout << YELLOW << this->target << " has been robotomized successfully" << RESET << std::endl;
	else
		std::cout << RED << this->target << " has failed to be robotomized" << RESET << std::endl;
}

void RobotomyRequestForm::setTarget(std::string target)
{
	this->target = target;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (target);
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &rhs)
{
	out << YELLOW << "RobotomyRequestForm " << rhs.getName() << " is ";
	if (rhs.getIsSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << rhs.getGradeToSign() << " to be signed and grade " << rhs.getGradeToExecute() << " to be executed" << RESET;
	return (out);
}