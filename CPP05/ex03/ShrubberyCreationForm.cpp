/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:21:55 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/07 22:49:31 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	this->target = other.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return (*this);
	this->target = other.target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file;
	std::string filename = this->target + "_shrubbery";
	file.open(filename.c_str());
	file << "     * " << std::endl;
	file << "    *** " << std::endl;
	file << "   ***** " << std::endl;
	file << "  ******* " << std::endl;
	file << " ********* " << std::endl;
	file << "    ||| " << std::endl;
	file << "    ||| " << std::endl;
	file.close();
}

void ShrubberyCreationForm::setTarget(std::string target)
{
	this->target = target;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &rhs)
{
	out << YELLOW << "ShrubberyCreationForm " << rhs.getName() << " is ";
	if (rhs.getIsSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << rhs.getGradeToSign() << " to be signed and grade " << rhs.getGradeToExecute() << " to be executed" << RESET;
	return (out);
}