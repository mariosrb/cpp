#include <fstream>
#include <iostream>

std::string	replace_all(std::string content, std::string s1, std::string s2)
{
	size_t	pos = 0;
	std::string	result = content;

	while ((pos = result.find(s1, pos)) != std::string::npos)
	{
		result = result.substr(0, pos) + s2 + result.substr(pos + s1.length());
		pos += s2.length();
	}
	return result;
}

void find_and_replace(std::ifstream& file, std::string s1, std::string s2, char **argv)
{
	if (!file.is_open()) {
		std::cout << "Error opening infile" << std::endl;
		return ;
	}
	std::string	content;
	std::string line;
	while (getline(file, line)) {
		content += line + "\n";
	}
	std::string	outputFilename = std::string(argv[1]) + ".replace";
	std::ofstream outputFile(outputFilename);
	if (!outputFile.is_open()) {
		std::cout << "Error creating output file" <<std::endl;
		return ;
	}
	content = replace_all(content, s1, s2);
	outputFile << content;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments. Must be 3" << std::endl;
		return (-1);
	}
	std::ifstream	file(argv[1]);
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	find_and_replace(file, s1, s2, argv);
	return (0);
}
