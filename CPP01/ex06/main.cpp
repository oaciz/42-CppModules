#include "Harl.hpp"

int main(int argc, char **argv){
	Harl harl;
	if (argc != 2){
		std::cerr << "Error" << std::endl;
		return (1);
	}

	std::string mainArray[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int i;
	for (i = 0; i < 4;i++) {
		if (argv[1] == mainArray[i])
			break;
	}
	switch (i) {
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
		break;
		case 4:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}