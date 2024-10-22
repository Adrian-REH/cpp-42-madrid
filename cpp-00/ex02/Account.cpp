#include "Account.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <vector>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
std::vector<std::pair<int, int> > depositHistory;
std::vector<std::pair<int, int> > withdrawalHistory;

void Account::_displayTimestamp(void) {
	std::cout << "[" 
				<< "1992"
				<< "01"
				<< "04"
				<< "_"
				<< "09"
				<< "15"
				<< "32"
				<< "] ";
}

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout
	<< "accounts:" << BLUE << _nbAccounts << RESET << ";"
	<< "total:" << BLUE << _totalAmount << RESET << ";"
	<< "deposits:" << BLUE << _totalNbDeposits << RESET << ";"
	<< "withdrawals:" << BLUE << _totalNbWithdrawals << RESET
	<<std::endl;
}

Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	depositHistory.resize(_nbAccounts);
	depositHistory[_accountIndex] = std::make_pair(0, 0);
	withdrawalHistory.resize(_nbAccounts);
	withdrawalHistory[_accountIndex] = std::make_pair(0, 0);
	_displayTimestamp();
	std::cout 
	<< "index:" << BLUE << _accountIndex << RESET << ";"
	<< "amount:" << BLUE << initial_deposit << RESET << ";"
	<<"created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout 
	<< "index:" << BLUE << _accountIndex << RESET << ";"
	<< "amount:" << BLUE << _amount << RESET << ";"
	<< "closed" << std::endl;
}

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	depositHistory[_accountIndex] = std::make_pair(_amount, deposit);
	_amount += deposit;
	_totalAmount += deposit;
	std::cout 
	<< "index:" << BLUE << _accountIndex << RESET <<";"
	<< "p_amount:" << BLUE << depositHistory[_accountIndex].first << RESET << ";"
	<< "deposit:" << BLUE << depositHistory[_accountIndex].second << RESET << ";"
	<< "amount:" << BLUE << Account::_amount << RESET << ";"
	<< "nb_deposits:" << BLUE << Account::_nbDeposits << RESET << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout
		<< "index:" << BLUE << _accountIndex << RESET << ";"
		<< "p_amount:" << BLUE << _amount << RESET<< ";"
		<< "withdrawal:" << RESET 
		<< "refused"<< std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	withdrawalHistory[_accountIndex] = std::make_pair(_amount, withdrawal);
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout 
	<< "index:" << BLUE << _accountIndex << RESET << ";"
	<< "p_amount:" << BLUE << withdrawalHistory[_accountIndex].first << RESET<< ";"
	<< "withdrawal:" << BLUE << withdrawalHistory[_accountIndex].second << RESET << ";"
	<< "amount:" << BLUE << _amount << RESET << ";"
	<< "nb_withdrawals:" << BLUE << _nbWithdrawals << RESET << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const{
	return (0);
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout 
	<< "index:" << BLUE << _accountIndex << RESET << ";"
	<< "amount:" << BLUE << _amount << RESET << ";"
	<< "deposits:" << BLUE << _nbDeposits << RESET << ";"
	<< "withdrawals:" << BLUE << _nbWithdrawals << RESET << std::endl;
}
