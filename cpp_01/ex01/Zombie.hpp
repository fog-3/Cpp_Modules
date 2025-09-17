#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctype.h>

class Zombie {
	private:
		std::string _name;
	public:
		Zombie(std::string zombieName);
		Zombie(void);
		~Zombie(void);
		void announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
