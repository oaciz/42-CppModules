#include <iostream>
using std::cout;
using std::endl;

int	main(int ac, char **av)
{
	int	i = 0;

	if(ac > 1)
	{
		std::string test; 
		while (av[++i])
		{
			test = av[i];
			std::transform(test.begin(), test.end(), test.begin(), ::toupper);
			cout << test << " ";
		}
		cout << endl;
	}
	else
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	return(0);
}