#ifndef DATA_HPP
#define DATA_HPP
#include <string>

class Data {
	private:
		std::string _name;
	public:
		Data();
		Data(std::string name);
		~Data();
		Data(const Data&);
		std::string getName() const ;
		Data &operator=(const Data &);
};

#endif