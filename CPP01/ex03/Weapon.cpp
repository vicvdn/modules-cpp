/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:04:44 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/03 17:55:29 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon ( std::string type ) : type(type) {
}

Weapon::~Weapon ( void ){
}

void	Weapon::setType(std::string type){
	this->type = type;
	return ;
}

const std::string&	Weapon::getType( void ){
	std::string& ref = this->type;
	return (ref);
}

// const std::string &Weapon::getType() {
//   return this->type;
// }