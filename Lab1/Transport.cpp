#include "Transport.h"
#include <iostream>
TTransport::TTransport()
{
	weight = 0;
	height = 0;
}

TTransport::TTransport(int _height, int _weight)
{
	SetHeight(_height);
	SetWeight(_weight);
}

TTransport::TTransport(const TTransport& p)
{
	weight = p.weight;
	height = p.height;
}

void TTransport::SetWeight(int _weight)
{
	if (_weight >= 0) this->weight = _weight;
	else std::cout << "Wrong argument" << std::endl;
}

void TTransport::SetHeight(int _height)
{
	if (_height >= 0) this->height = _height;
	else std::cout << "Wrong argument" << std::endl;
}
double TTransport::GetWeight()
{
	return weight;
}
double TTransport::GetHeight()
{
	return height;
}

