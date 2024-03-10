#include "RPN.hpp"

int main(int argc, char *argv[])
{
	std::stack<int> stack;
	if (argc != 2)
	{
		std::cout << "Wrong arguman size." << std::endl;
		return (0);
	}
	start(stack, argv[1]);
}
