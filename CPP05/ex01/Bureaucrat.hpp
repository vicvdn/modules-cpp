/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:28:16 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/07 09:12:41 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Form;

class Bureaucrat{
	
	private:
		std::string const name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int gradeGiven);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat 			&operator=(const Bureaucrat &other);
		int 				getGrade() const;
		const std::string	getName() const;
		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw(); //this is the only method that is mandatory to implement
		};
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif