#include "Harl.hpp"
#include <iostream>

using std::endl;
void Harl::debug( void )
{
	std::cout << "7XL-çift peynirli-üçlü turşu-özel-ketçaplı burgerime fazladan domuz pastırması yemeyi seviyorum. Gerçekten seviyorum!" << endl;
}

void Harl::info( void )
{

	std::cout << "Ekstra domuz pastırması eklemenin daha fazla paraya mal olduğuna inanamıyorum. Burgerime yeterince pastırma koymadınız! Yapsaydınız, daha fazlasını istemezdim" << endl;
}

void Harl::warning( void )
{

	std::cout << "Bence bedavaya fazladan pastırma yemeyi hak ediyorum. Ben yıllardır geliyorum, sen geçen aydan beri burada çalışmaya başladın." << endl;
}

void Harl::error( void )
{

	std::cout << "Bu kabul edilemez! Şimdi müdürle konuşmak istiyorum." << endl;
}

void Harl::complain( string level )
{
	const char *labels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fun[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for (int i = 0; i < 4; i++)
		if (std::strcmp(labels[i],level.c_str()) == 0)
		{
			std::cout << "[ " << labels[i] << " ]" << std::endl;
			return (this->*fun[i])();
		}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}