#include "TComplex.h"
#include <math.h>
#define PI 3.14159265


TComplex::TComplex()
{
	re = 0;
	im = 0;
}

TComplex::TComplex(double _re, double _im)
{
	re = _re;
	im = _im;
}

TComplex::TComplex(const TComplex& p)
{
	re = p.re;
	im = p.im;
}

double TComplex::GetRe()
{
	return re;
}

double TComplex::GetIm()
{
	return im;
}

void TComplex::SetRe(double _re)
{
	re = _re;
}

void TComplex::SetIm(double _im)
{
	im = _im;
}

TComplex TComplex::operator+ (TComplex& p)
{
	TComplex res;
	res.re = re + p.re;
	res.im = im + p.im;
	return res;
}

TComplex TComplex::operator- (TComplex& p)
{
	TComplex res;
	res.re = re - p.re;
	res.im = im - p.im;
	return res;
}

TComplex TComplex::operator* (TComplex& p)
{
	TComplex res;
	res.re = re * p.re - im * p.im;
	res.im = re * p.im - im * p.re;
	return res;
}

TComplex TComplex::operator/ (TComplex& p)
{
	TComplex res;
	res.re = (re * p.re + im * p.im) * 1.0 / (p.re * p.re + p.im * p.im);
	res.im = (im * p.re - re * p.im) * 1.0 / (p.re * p.re + p.im * p.im);
	return res;
}

TComplex TComplex::operator=(const TComplex& p)
{
	re = p.re;
	im = p.im;
	return*this;
}

bool TComplex::operator==(TComplex& p)
{
	if ((p.re == re) && (p.im = im))
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& B, TComplex& A)
{
	std::cout << A.re << " + " << A.im << "i" << std::endl;
	return B;
}

std::istream& operator>>(std::istream& B, TComplex& A)
{
	B >> A.re;
	B >> A.im;
	return B;
}

void TComplex::TrigForma()
{
	std::cout << ABS() << " * (cos(" << atan(im / re) << ") + i * sin(" << atan(im / re) << "))";
}

double TComplex::ABS()
{
	return pow((pow(re, 2) + pow(im, 2)), 0.5);
}

void TComplex::Pow(double n)
{
	double arg = atan(im / re);
	if (n >= 1)
	{
		re = pow(ABS(), n) * cos(n * arg);
		im = pow(ABS(), n) * sin(n * arg);
	}
	else
	{
		double k = 1 / n * 1.0;
		re = pow(ABS(), n) * cos(arg / k);
		im = pow(ABS(), n) * sin(arg / k);
	}
}
