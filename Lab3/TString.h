#include <iostream>
using namespace std;
class TString
{
public:
	TString();
	TString(char* _stroka);
	TString(int _len, char b);
	TString(const TString& p);
	~TString();

	char* GetString();
	int GetLength();
	void SetString(const char* _stroka);
	void SetCountOfSplit(int count);
	int GetCountOfSplit();

	int StrLength(const char* str);
	int Find(char n);
	int Find(TString& p);
	TString* Split(char c);

	TString operator + (const char* a);
	TString operator + (const TString& p);
	TString& operator = (const TString& p);
	TString& operator = (const char* a);
	bool operator == (TString& p);
	bool operator < (TString& p);
	bool operator > (TString& p);
	char& operator [] (int n);
	friend ostream& operator << (ostream& B, TString& A);
	friend istream& operator >> (istream& B, TString& A);

protected:
	char* stroka;
	int length;
	int countSplit;
};

