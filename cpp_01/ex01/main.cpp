#include "Zombie.hpp"

bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}
   

int main(int argc, char **argv){
    int N = 4;
    Zombie *zHorde;

    if (argc > 1 && is_digits(argv[1])){
        N = atoi(argv[1]);
    }
    zHorde = zombieHorde(N, "Ralf");
    for (int i = 0; i < N; i++)	{
       std::cout << "[" << i << "]: ";
	   zHorde[i].announce();
    }
    delete[] zHorde;
    return (0);
}
