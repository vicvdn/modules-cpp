/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:13:43 by ubuntu            #+#    #+#             */
/*   Updated: 2024/06/07 11:33:06 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HARL_HPP
#define	HARL_HPP

#include <string>
#include <iostream>

class	Harl{

private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
public:
	Harl();
	~Harl();
	void	complain(std::string level);
};

#endif