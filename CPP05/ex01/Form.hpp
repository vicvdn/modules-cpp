/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:07:52 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/01 19:40:10 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Form {

	private:
		std::string const name;
		bool isSigned;
		int const gradeToSign;
		int const gradeToExecute;
	
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		~Form();
		Form(const Form &other);
		Form &operator=(const Form &other);
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
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);

#endif