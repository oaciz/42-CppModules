#include <fstream>
#include <iostream>
#include <string>

using std::ofstream;
using std::string;
using std::endl;
using std::cout;
using std::cerr;
using std::ifstream;

int	main(int ac, char **av)
{
	if (ac != 4)
		return 1;
	string	filename = (string)av[1];
	string	search = (string)av[2];
	string	replace = (string)av[3];
	string line;
	ofstream output(filename + ".replace"); //output stream
	ifstream input(filename); // input stream

	if (!input.good()){ // doğru bir şekilde açılıp açılmadığını kontrol eder
		std::cerr << filename << ": Invalid file" << std::endl;
		return 1;
	}
	while (getline(input,line)){
		size_t position;
		while ((position = line.find(search)) != string::npos){ // satır içerisindeki karşılaşmayı bulur, bulamayana kadar tekrar eder
			line.erase(position, search.length()); // satırdan aranan kelimeyi siler.
			line.insert(position, replace); // değiştirilecek olan kelimeyi karşılaşma yerine ekler.
		}
		output << line << endl;
	}
	return 0;
}