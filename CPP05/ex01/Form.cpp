/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:08:33 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/07 09:11:00 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), gradeToSign(150), gradeToExecute(150){
	isSigned = false;
	std::cout << GREEN << "Form " << name << " created" << RESET << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
	isSigned = false;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << GREEN << "Form " << name << " created" << RESET << std::endl;
}

Form::~Form(){
	std::cout << RED << "Form " << name << " destroyed" << RESET << std::endl;
}

Form::Form(const Form &other): name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}
Form &Form::operator=(const Form &rhs){
	if (this != &rhs)
		isSigned = rhs.isSigned;
	return *this;
}

const char *Form::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw(){
	return "Grade is too low";
}


void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}

std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const{
	return isSigned;
}

int Form::getGradeToSign() const{
	return gradeToSign;
}

int Form::getGradeToExecute() const{
	return gradeToExecute;
}

std::ostream &operator<<(std::ostream &out, const Form &rhs){
	out << "Form " << rhs.getName() << " is ";
	if (rhs.getIsSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires a grade " << rhs.getGradeToSign() << " to be signed and a grade " << rhs.getGradeToExecute() << " to be executed";
	return out;
}