/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:23:27 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/30 18:03:44 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::getNbAccounts( void ){
	return (_nbAccounts);
}

int Account::getTotalAmount( void ){
	return (_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ){
	for(int i = 0; i < 8; i++){
		std::cout << "index:" << Account(i)._accountIndex;
		std::cout << "amount:" << Account(i)._amount;
		std::cout << "deposits:" << Account(i)._nbDeposits;
		std::cout << "withdrawals:" << Account(i)._nbWithdrawals << std::endl;
	}
}

void	Account::makeDeposit( int deposit) {
	
}