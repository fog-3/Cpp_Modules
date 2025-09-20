#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup" << std::endl << "burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put" << std::endl << \
                "bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning (void)
{
    std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming for" << std::endl << \
                    "years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    int i;

    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*fptr[4])() = {&Harl::debug,&Harl::info, &Harl::warning, &Harl::error};

    i = 0;
    while(i < 4){
        if (levels[i] == level){
            (this->*fptr[i])();
            return;
        }
        i++;
    }
    std::cout << "No Valid Level.\n";
}
