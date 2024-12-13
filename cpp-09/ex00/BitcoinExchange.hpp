#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <map>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

class BitcoinExchange {
	private:
		std::map<std::string, float>	_db;
		bool							_isMigrate;
		const char							*_file_db;
		char							*_file_src;
	public:
		BitcoinExchange();
		BitcoinExchange(char *, char *);
		BitcoinExchange(char *);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const&);
		BitcoinExchange & operator=(const BitcoinExchange &);
		void evaluateSrc();
		void migrateDB();
};

//Utils
std::deque<std::string>	readFile(const char *_filename);
std::deque<std::string>	split(std::string &str, char delimiter);
std::string				strtrim(const std::string& str);
bool					isValidDate(const std::string& date);

#endif