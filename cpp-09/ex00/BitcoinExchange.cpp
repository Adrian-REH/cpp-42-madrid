#include "BitcoinExchange.hpp"
#include <iomanip>

BitcoinExchange::BitcoinExchange(): _isMigrate(false), _file_db("data.csv"), _file_src(NULL) {
	std::cout << "[Build] BitcoinExchange class" << std::endl;
}

BitcoinExchange::BitcoinExchange(char * file_src) : _isMigrate(false), _file_db("data.csv"), _file_src(file_src) {
	std::cout << "[Build] BitcoinExchange class | src_file: " << _file_src  << std::endl;
}

BitcoinExchange::BitcoinExchange(char * file_db, char * file_src) : _isMigrate(false), _file_db(file_db), _file_src(file_src) {
	std::cout << "[Build] BitcoinExchange class | src_file: " << _file_src <<" | db_file: " << _file_db <<  std::endl;

}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "[Destroy] BitcoinExchange class" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src) {
	std::cout << "[Copy] BitcoinExchange class" << std::endl;
	*this = src;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & src) {
	std::cout << "[Assignament Operator] BitcoinExchange class" << std::endl;
	if (this == &src)
		return *this;
	this->_db  = src._db;
	this->_file_db  = src._file_db;
	this->_file_src  = src._file_src;
	this->_isMigrate  = src._isMigrate;
	return *this;
}

void BitcoinExchange::migrateDB() {
	std::deque<std::string>				content;
	std::deque<std::string>::iterator	it;
	std::deque<std::string>				temp;

	content = readFile(_file_db);
	for (it = content.begin(); it != content.end(); it++) {
		std::string str = strtrim(*it);
		temp = split(str, ',');
		if (temp.size() > 2 || temp.size() == 0)
			std::cout << "Invalid Arguments in csv" << std::endl;
		str = strtrim(temp.front());
		if (!isValidDate(temp.front()))
		{
			std::cout << "bad input => " << temp.front() << std::endl;
			continue;
		}
		float val = atof(temp.back().c_str());
		if (val < 0)
		{
			std::cout << "Invalid value, the number should be more then 0 "<< std::endl;
			continue;
		}

		_db.insert(std::make_pair(temp.front(), val));
	}
	_isMigrate = _db.size() > 0;
}

void BitcoinExchange::evaluateSrc() {
	std::deque<std::string>				content;
	std::deque<std::string>::iterator	it;
	std::map<std::string, unsigned int>	argument;
	std::deque<std::string>				temp;

	if (!_isMigrate)
		throw std::invalid_argument("Error with data csv");
	content = readFile(_file_src);
	std::cout << content.size() <<  std::endl;
	for (it = content.begin(); it != content.end(); it++) {
		std::string str = strtrim(*it);
		temp = split(str, '|');
		if (temp.size() > 2 || temp.size() == 0)
			std::cout << "Invalid Arguments in file: "<< _file_src << std::endl;
		str = strtrim(temp.front());
		if (!isValidDate(str))
		{
			std::cout << "Error: bad input => " << temp.front() << std::endl;
			continue;
		}
		float val = atof(temp.back().c_str());
		if (val > 1000 || val < 0)
		{
			std::cout << "Error: too large a number "<< temp.back() << std::endl;
			continue;
		}
		
		std::cout << std::fixed	<< std::setprecision(2) << str
					<< " => "
					<< val
					<< " = "
					<< _db[str]
					<< std::endl;
	}
}

std::map<std::string, float> BitcoinExchange::getColections() const {
	return _db;
}

bool BitcoinExchange::getIsMigrate() const {
	return _isMigrate;
}



//--------------------------------------------------UTILS-----------------------------------------------
std::string strtrim(const std::string& str) {
	size_t start;
	size_t end;

	start = str.find_first_not_of(" \t\n\r\f\v");
	if (start == std::string::npos)
		return ("");
	end = str.find_last_not_of(" \t\n\r\f\v");
	return (str.substr(start, end - start + 1));
}

bool isValidDate(const std::string& date) {
	std::tm tm = {};
	char* res = strptime(date.c_str(), "%Y-%m-%d", &tm);
	return (res != NULL && *res == '\0');
}

std::deque<std::string> split(std::string &str, char delimiter) {
	std::stringstream		sstr(str);
	std::string				token;
	std::deque<std::string>	result;
	while (std::getline(sstr, token, delimiter)){
		result.push_back(token);
	}
	return result;
}

std::deque<std::string> readFile(const char *_filename)
{
	std::deque<std::string>		content;
	std::string					line;
	std::map<std::string, int>	exchange;
	std::ifstream				inFile(_filename);

	if (!inFile)
		throw std::runtime_error("Error: could not open file");
	while (std::getline(inFile, line))
		content.push_back(line);
	inFile.close();
	return content;
}


std::ostream & operator<<(std::ostream &io, const BitcoinExchange &val) {
	std::map<std::string, float> db = val.getColections();
	std::map<std::string, float>::iterator it;
	io << "Key\tValue" << std::endl;
	for (it = db.begin(); it != db.end(); it++) {
		io << "first: " << (*it).first;
		io << "\tsecond: " << (*it).second << std::endl;
	}
	io << "IsMigrate: " << val.getIsMigrate();
	return io;
}
