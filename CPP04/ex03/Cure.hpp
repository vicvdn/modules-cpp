/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:34:08 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/02 17:30:15 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	
	public:
		Cure();
		Cure(const Cure& copy);
		Cure& operator=(const Cure& rhs);
		virtual ~Cure();
		
		AMateria*	clone(void) const;
		void use(ICharacter& character);
};

#endif