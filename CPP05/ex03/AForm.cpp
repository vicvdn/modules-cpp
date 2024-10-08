/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:46:15 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/07 19:02:58 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), gradeToSign(150), gradeToExecute(150){
	isSigned = false;
	std::cout << GREEN << "AForm " << name << " created" << RESET << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
	isSigned = false;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << GREEN << "AForm " << name << " created" << RESET << std::endl;
}

AForm::~AForm(){
	std::cout << RED << "AForm " << name << " destroyed" << RESET << std::endl;
}

AForm::AForm(const AForm &other): name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}
AForm &AForm::operator=(const AForm &rhs){
	if (this != &rhs)
		isSigned = rhs.isSigned;
	return *this;
}

const char *AForm::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw(){
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw(){
	return "Form is not signed";
}


void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

const std::string AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const{
	return isSigned;
}

int AForm::getGradeToSign() const{
	return gradeToSign;
}

int AForm::getGradeToExecute() const{
	return gradeToExecute;
}

std::ostream &operator<<(std::ostream &out, const AForm &rhs){
	out << "AForm " << rhs.getName() << " is ";
	if (rhs.getIsSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires a grade " << rhs.getGradeToSign() << " to be signed and a grade " << rhs.getGradeToExecute() << " to be executed";
	return out;
}