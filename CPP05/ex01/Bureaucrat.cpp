/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:06:48 by victoirevau       #+#    #+#             */
/*   Updated: 2024/09/25 20:11:02 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//CONSTRUCTORS

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade){
}

Bureaucrat::Bureaucrat() : name("default"), grade(150){
}

Bureaucrat::Bureaucrat(std::string name, int gradeGiven) : name(name){
	if (gradeGiven < 1)
		throw Bureaucrat::GradeTooHighException();
	if (gradeGiven > 150)
		throw Bureaucrat::GradeTooLowException();
	grade = gradeGiven;
	std::cout << GREEN << "Bureaucrat " << name << " created" << RESET << std::endl;
}

//ASSIGNATION OPERATOR
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other)
		grade = other.grade;
	std::cout << GREEN << "Constructor Bureaucrat by assign operator" << RESET << "\n";
	return *this;
}

//GETTERS

const std::string Bureaucrat::getName() const{
	return name;
}

int Bureaucrat::getGrade() const{
	return grade;
}


//INCREMENT AND DECREMENT GRADE

void Bureaucrat::incrementGrade(){
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade(){
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade is too low");
}

Bureaucrat::~Bureaucrat(){
	std::cout << RED << "Bureaucrat " << name << " destroyed" << RESET << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
	out << "Bureaucrat " << rhs.getName() << " has grade " << rhs.getGrade();
	return out;
}