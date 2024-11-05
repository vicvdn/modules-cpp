/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:36:03 by victoirevau       #+#    #+#             */
/*   Updated: 2024/11/05 15:46:20 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


template <class T> 
Array<T>::Array() : array(new T[0]), arraySize(0) {
}

template <class T> 
Array<T>::Array(unsigned int n) : array(new T[n]), arraySize(n) {
	for (int i = 0; i < arraySize; i++)
		array[i] = 0;
}
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
Array<T>& Array<T>::operator=(const Array &copy)
{
	if (this != &copy)
	{
		array = copy.array;
		arraySize = copy.arraySize;
	}
	return (*this);
}

template <class T> 
T &Array<T>::operator[](unsigned int i) {
	if (i >= arraySize)
		throw std::out_of_range("Index out of range");
	return array[i];
}

template <class T> 
const T &Array<T>::operator[](unsigned int i) const{
	if (i >= arraySize)
		throw std::out_of_range("Index out of range");
	return array[i];
}

template <class T> 
unsigned int Array<T>::size() const {
	return arraySize;
}