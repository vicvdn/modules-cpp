/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:23:27 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/31 15:27:07 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void ){
	return Account::_nbAccounts;
}

int Account::getTotalAmount( void ){
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ){
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){
	return Account::_totalNbWithdrawals;
}

void	Account::_displayTimestamp( void ){
	std::time_t	curTime = std::time(0);
	char timeStr[100];
	std::strftime(timeStr, sizeof(timeStr), "[%Y%m%d_%H%M%S]", std::localtime(&curTime));
	std::cout << timeStr << " ";
}

void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit) {
	int	temp = this->_amount;
	
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << temp << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std:: endl;
}

bool Account::makeWithdrawal( int withdrawal) {
	int	temp = this->_amount;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << temp << ";";
	if (withdrawal > checkAmount()) {
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	else {
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;
		this->_nbWithdrawals += 1;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
}

Account::Account( void ){
}

Account::Account (int initial_deposit) {
	Account::_displayTimestamp();
	_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}