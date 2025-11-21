#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_database = other._database;
	}
	return (*this);
}

std::string	BitcoinExchange::trim(const std::string& str) const {
	size_t	start = 0;
	size_t	end = str.length();

	while (start < end && (str[start] == ' ' || str[start] == '\t'))
		start++;
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
		end--;

	return (str.substr(start, end - start));
}

// ex : "123avc" --> value = 123 | end pointe vers a;
bool BitcoinExchange::isValidValue(const std::string &valueStr, double &value) const {
	char	*end;

	value = strtod(valueStr.c_str(), &end);
	if (*end != '\0' && *end != '\n' && *end != '\r')
		return (false);
	return (true);
}

// Une date qui a pas 10 cara = invalid plus pas tiret place 4 et 7 = invalid
bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);

	// on verifie que cest bien des digits
	for (size_t i = 0; i < date.length(); i++) {
		if (i != 4 && i != 7 && !isdigit(date[i])) {
			return (false);
		}
	}

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (year < 1000 || year > 9999)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
}

bool BitcoinExchange::initialize(const std::string& dbFile) {
	return (loadDatabase(dbFile));
}

void BitcoinExchange::processInput(const std::string& inputFile) {
	std::ifstream	file(inputFile.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string line;
	bool		firstLine = true;

	while (std::getline(file, line)) {
		if (firstLine) {
			firstLine = false;
			continue;
		}

		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 1));
	}
}
