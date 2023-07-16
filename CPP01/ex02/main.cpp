#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::setfill;

int	main()
{
	string	str = "HI THIS IS BRAIN";
	string	*stringPTR = &str;
	string	&stringREF = str;

	cout << setw(35) << "\033[32mADRESLER" << endl;
	cout << "-----------------------------------------------------------" << endl;

	cout << "String değişkeninin bellek adresi: " << &str << endl;
	cout << "StringPTR tarafından tutulan bellek adresi: " << stringPTR << endl;
	cout << "StringREF tarafından tutulan bellek adresi: " << &stringREF << endl;

	cout << "-----------------------------------------------------------" << endl;
	cout << setw(31) << "DEĞERLER" << endl;

	cout << "-----------------------------------------------------------" << endl;

	cout << "string değişkeninin değeri: " << str << endl;
	cout << "stringPTR tarafından işaret edilen değer: " << *stringPTR << endl;
	cout << "stringREF tarafından işaret edilen değer: " << stringREF << endl;

	cout << "-----------------------------------------------------------" << endl;

}