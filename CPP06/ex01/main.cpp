/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:48:07 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/17 11:00:00 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data data;
	data.data1 = "Hello World!";

	std::cout << "Message : " << data.data1 << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	
	std::cout << "Raw : " << raw << std::endl;
	Data *ptr = Serializer::deserialize(raw);
	
	std::cout << "Message deserialized : " << ptr->data1 << std::endl;
	return 0;
}