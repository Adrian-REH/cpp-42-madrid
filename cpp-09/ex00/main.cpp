
#include "BitcoinExchange.hpp"

int main(int argc, char **arg) {
	if (argc != 2)
		return std::cout << "Invalid Argument" << std::endl, 1;
	BitcoinExchange btcExc(arg[1]);
	btcExc.migrateDB();
	btcExc.evaluateSrc();
}