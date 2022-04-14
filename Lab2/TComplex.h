#include <iostream>
#include <math.h>


class TComplex
{
public:
	static const double PI;
	TComplex();
	TComplex(double _re, double _im);
	TComplex(const TComplex& p);
	double GetRe();
	double GetIm();
	void SetRe(double _re);
	void SetIm(double _im);
	// доп задания
	double ABS();
	void Pow(double n);
	void TrigForma();
	//
	TComplex operator + (TComplex& p);
	TComplex operator * (TComplex& p);
	TComplex operator / (TComplex& p);
	TComplex operator - (TComplex& p);
	TComplex operator = (const TComplex& p);
	bool operator == (TComplex& p);
	friend std::ostream& operator << (std::ostream& B, TComplex& A);
	friend std::istream& operator >> (std::istream& B, TComplex& A);


private:
	double re;
	double im;
};
