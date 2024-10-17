/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:36:03 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/17 16:38:01 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


template <class T> 
Array<T>::Array() : array(NULL), arraySize(0) {}

template <class T> 
Array<T>::Array(unsigned int n) : array(new T[n]), arraySize(n) {}
//here new T[n] is an alloced array of n elements of type T

template <class T> 
Array<T>::Array(const Array &copy) : array(new T[copy.arraySize]), arraySize(copy.arraySize) {
	for (unsigned int i = 0; i < copy.arraySize; i++)
		array[i] = copy.array[i];
}

template <class T> 
Array<T>::~Array() {
	delete[] array;
}

template <class T> 
T &Array<T>::operator[](unsigned int i) {
	if (i >= arraySize)
		throw std::out_of_range("Index out of range");
	return array[i];
}

template <class T> 
unsigned int Array<T>::size() const {
	return arraySize;
}