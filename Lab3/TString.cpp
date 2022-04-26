#include "TString.h"
using namespace std;
TString::TString()
{
	length = 0;
	stroka = 0;
	countSplit = 0;
}

int TString::StrLength(const char* str)
{
	int i = 0;
	while (str[i] != '\0')  
		i++;
	return i;
}

TString::TString(char* _stroka): TString()
{
	if (_stroka == 0)
		throw "Dlina stroki == 0, ne rabotaet";
	length = StrLength(_stroka) + 1;
	stroka = new char[length];
	for (int i = 0; i < length; i++)
		stroka[i] = _stroka[i];
}

TString::TString(int _len, char a): TString()
{
	if (_len == 0)
		throw "Dlina stroki == 0, ne rabotaet";
	length = _len + 1;
	stroka = new char[length];
	for (int i = 0; i < _len; i++)
		stroka[i] = a;
	stroka[_len] = '\0';
}

TString::TString(const TString& p)
{
	length = p.length;
	countSplit = p.countSplit;
	stroka = new char[length];
	for (int i = 0; i < length; i++)
		stroka[i] = p.stroka[i];
}

TString::~TString()
{
	if (stroka != 0)
	{
		delete[] stroka;
		stroka = 0;
	}
	length = 0;
	countSplit = 0;
}

char* TString::GetString()
{
	return stroka;
}

int TString::GetLength()
{
	return length;
}

void TString::SetString(const char* _stroka)
{
	if (_stroka == 0)
		throw "Dlina stroki == 0, ne rabotaet";
	length = StrLength(_stroka) + 1;
	stroka = new char[length];
	for (int i = 0; i < length; i++)
		stroka[i] = _stroka[i];
}

// первое вхождение символа
int TString::Find(char n)
{
	for (int i = 0; i < length - 1; i++) 
	{
		if (stroka[i] == n)
			return i;
	}
}

int TString::GetCountOfSplit()
{
	return countSplit;
}

//поиск вхождения подслова
int TString::Find(TString& p)
{
	if (p.length > length)
		return -1;
	for (int i = 0; i < length; i++)
	{
		bool flag = 1;
		for (int j = 0; j < p.length - 1; j++)
		{
			if (stroka[i + j] != p.stroka[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			return i;
	}
	return -1;
}

// разбиение на подслова по символу
TString* TString::Split(char c)
{
	int count = 0;
	for (int i = 0; i < length - 1; i++)	
	{
		if (stroka[i] == c)	
			count++;
	}
	if (count == 0) return this;
	
	count++;
	TString* strings = new TString[count];
	int start = 0;
	int index = 0;
	for (int i = 0; i < length; i++)
	{
		if (stroka[i] == c)
		{
			strings[index].length = i - start + 1;
			delete[] strings[index].stroka;
			strings[index].stroka = new char[strings[index].length];
			for (int j = 0; j < strings[index].length - 1; j++)  
				strings[index].stroka[j] = stroka[j + start];
			strings[index].stroka[strings[index].length - 1] = '\0';
			index++;
			start = i + 1;
		}
	}
	strings[index].length = length - start;
	delete[] strings[index].stroka;
	strings[index].stroka = new char[strings[index].length];
	for (int k = 0; k < strings[index].length; k++)  
		strings[index].stroka[k] = stroka[k + start];
	index++;
	SetCountOfSplit(count);
	return strings;
}

// перегруженные операции
TString TString::operator+(const char* a)
{
	if (a == 0)
		return *this;
	TString A;
	int len = length + StrLength(a);
	A.stroka = new char[len];
	A.length = len;
	for (int i = 0; i < length - 1; i++)
		A.stroka[i] = stroka[i];
	for (int j = length - 1; j < len; j++)
		A.stroka[j] = a[j - length + 1];
	return A;
}

TString TString::operator+(const TString& p)
{
	if (p.stroka == 0)
		return *this;
	TString A;
	int len = length + p.length - 1;
	A.stroka = new char[len];
	A.length = len;
	for (int i = 0; i < length - 1; i++)
		A.stroka[i] = stroka[i];
	for (int j = length - 1; j < len; j++)
		A.stroka[j] = p.stroka[j - length + 1];
	return A;
}

TString& TString::operator=(const TString& p)
{
	if (this == &p)
		return *this;
	if (stroka != 0)
		delete[] stroka;
	length = p.length;
	stroka = new char[length];
	for (int i = 0; i < length; i++)
		stroka[i] = p.stroka[i];
	return *this;
}

TString& TString::operator=(const char* a)
{
	if (stroka != 0)
		delete[] stroka;
	length = StrLength(a) + 1;
	stroka = new char[length];
	for (int i = 0; i < length; i++)
		stroka[i] = a[i];
	return *this;
}

bool TString::operator==(TString& p)
{
	if (length != p.length) return false;
	for (int i = 0; i < length; i++)
	{
		if (stroka[i] != p.stroka[i]) return false;
	}
	return true;
}

bool TString::operator<(TString& p)
{
	int len = length > p.length ? p.length : length;
	for (int i = 0; i < len; i++)
	{
		if (stroka[i] < p.stroka[i]) return true;
		else if (stroka[i] > p.stroka[i]) return false;
	}
	if (length >= p.length) return false;
	else return true;
}

bool TString::operator>(TString& p)
{
	int len = length > p.length ? p.length : length;
	for (int i = 0; i < len; i++)
	{
		if (stroka[i] < p.stroka[i]) return false;
		else if (stroka[i] > p.stroka[i]) return true;
	}
	if (length >= p.length) return true;
	else return false;
}

char& TString::operator[](int n)
{
	if (stroka == 0) 
		throw "Stroka pusta";
	if (n > length - 1 || n < 0) 
		throw "chto-to ne tak";
	return stroka[n];
}

void TString::SetCountOfSplit(int count)
{
	countSplit = count;
}

ostream& operator<<(ostream& B, TString& A)
{
	for (int i = 0; i < A.length; i++)  B << A.stroka[i];
	return B;
}

istream& operator>>(istream& B, TString& A)
{
	B >> A.length;
	A.length++;
	if (A.stroka != 0) delete[] A.stroka;
	A.stroka = new char[A.length];
	for (int i = 0; i < A.length - 1; i++)  B >> A.stroka[i];
	A.stroka[A.length - 1] = '\0';
	return B;
}
