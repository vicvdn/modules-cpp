/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:01:22 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/02 17:30:12 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	
	public:
		Ice();
		Ice(const Ice& copy);
		Ice& operator=(const Ice& rhs);
		virtual ~Ice();
		
		AMateria*	clone(void) const;
		void use(ICharacter& character);
};

#endif