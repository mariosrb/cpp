#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {

public:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

};

int	string_to_int(std::string level);

#endif
