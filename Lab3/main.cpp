#include "TString.h"
#include <iostream>
inline void line()
{
	std::cout << std::endl;
}


int main()
{
	TString str1;
	TString str2;
	TString str3(7, 'v');
	TString str4 = str2;
	TString* split;
	str2.SetString("city");
	str1.SetString("He had always hated the streets of a ");
	str3 = str2;
	str4 = str1 + str3;
	std::cout << str4;
	line();

	std::cout << "Index of first 's' in '" << str4 << "' == " << str4.Find('s') << "\t";
	line();

	if (str2 == str3) std::cout << "str2 == str3\n";
	if (str1 < str3) std::cout << "str1 < str3\n";
	if (str2 > str4) std::cout << "str2 > str4\n";
	line();

	std::cout << "str1.string[12] == " << str1[12] << std::endl;
	line();
	TString str5;
	TString str6;
	str5.SetString("singtr");
	str6.SetString("tr");
	std::cout << "'tr' v slove 'singtr' nachinaetsya s indexa == " << str5.Find(str6) << "\n";
	line();
	str1.SetString("cat,/dog/and/rat");
	std::cout << str1;
	line();
	split = str1.Split('/');
	for (int i = 0; i < str1.GetCountOfSplit(); i++)
	{
		std::cout << split[i] << " ";
	}
	return 0;
}