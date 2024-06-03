/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:01:31 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/03 17:48:31 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

private:
	std::string type;
	
public:
	Weapon( std::string type);
	~Weapon();
	void			setType( std::string type );
	// std::string&	getType( void );
	const std::string &getType();
};

#endif