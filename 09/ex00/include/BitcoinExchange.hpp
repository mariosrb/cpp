#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

class BitcoinExchange {
	private:
		std::map<std::string, double>	_database;

		bool		loadDatabase(const std::string& filename);
		bool		isValidDate(const std::string& date) const;
		bool		isValidValue(const std::string& valueStr, double& value) const;
		std::string	trim(const std::string& str) const;
		std::string	findClosestDate(const std::string& date) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		bool	initialize(const std::string& dbFile);
		void	processInput(const std::string& inputFile);
};

#endif
