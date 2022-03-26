#include "PassengerTrain.h"
#include <iostream>
TPass::TPass()
{
	maxpassengers = 0;
	weight = 662;
	height = 5;
	wagons = 10;
}

TPass::TPass(int _maxpassengers): TPass()
{
	SetMaxPassengers(_maxpassengers);
}

TPass::TPass(const TPass& p): TRailroad()
{
	maxpassengers = p.maxpassengers;
}

void TPass::SetMaxPassengers(int _maxpassengers)
{
	if (_maxpassengers >= 0) this->maxpassengers = _maxpassengers;
	else std::cout << "Wrong argument" << std::endl;
}

int TPass::GetMaxPassengers()
{
	return maxpassengers;
}

void TPass::Print()
{
	std::cout << "Passenger Train\n" << "Weight = " << GetWeight() << " tonns\n" << "Height = " << GetHeight() <<
	" meters\n" << "Wagons = " << GetWagons() << "\n" << "Max passengers = " << GetMaxPassengers() <<
	"\n" << std::endl;
}
