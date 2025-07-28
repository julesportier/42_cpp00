#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*********************
 * HELPERS FUNCTIONS *
 * ******************/
static void print_timestamp()
{
	const int size = 20;
	char str[20] = {0};
	const std::time_t time = std::time(NULL);
	std::strftime(str, 19, "[%Y%m%d_%H%M%S]", std::localtime(&time));
	std::cout << str;
}

/******************
 * PUBLIC METHODS *
 * ***************/
Account::Account(int initial_deposit)
	: _accountIndex(Account::_nbAccounts)
	, _amount(initial_deposit)
{
	++Account::_nbAccounts;
	Account::_totalAmount += initial_deposit;
	print_timestamp();
	std::cout
		<< " index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";created\n";
}

Account::~Account()
{
	print_timestamp();
	std::cout
		<< " index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed\n";
	Account::_totalAmount -= this->_amount;
	++Account::_nbAccounts;
}

// Operations on static members
int Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	print_timestamp();
	std::cout
		<< " accounts:" << Account::getNbAccounts()
		<< ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits()
		<< ";withdrawals:" << Account::getNbWithdrawals()
		<< '\n';
}

// Operations on instance specific members
void Account::makeDeposit(int deposit)
{
	if (deposit <= 0)
		return ;
	print_timestamp();
	std::cout
		<< " index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";deposit:" << deposit;
	this->_amount += deposit;
	++this->_nbDeposits;
	Account::_totalAmount += deposit;
	++Account::_totalNbDeposits;
	std::cout
		<< ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits
		<< '\n';
}

bool Account::makeWithdrawal(int withdrawal)
{
	print_timestamp();
	std::cout
		<< " index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount;
	if (this->_amount < withdrawal) {
		std::cout << ";withdrawal:refused\n";
		return (false);
	}
	this->_amount -= withdrawal;
	++this->_nbWithdrawals;
	Account::_totalAmount -= withdrawal;
	++Account::_totalNbWithdrawals;
	std::cout
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals
		<< '\n';
	return (true);
}

int Account::checkAmount() const
{
	return (this->_amount);
}

void Account::displayStatus() const
{
	print_timestamp();
	std::cout
		<< " index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< '\n';
}
