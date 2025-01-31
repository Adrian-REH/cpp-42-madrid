
#include "BitcoinExchange.hpp"

int main(int argc, char **arg) {
	if (argc != 2)
		return std::cout << "Invalid Argument" << std::endl, 1;
	BitcoinExchange btcExc(arg[1]);
	try {
		btcExc.migrateDB();
		btcExc.evaluateSrc();
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}