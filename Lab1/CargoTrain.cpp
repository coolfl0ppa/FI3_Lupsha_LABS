#include "CargoTrain.h"
#include <iostream>
TCargoTrain::TCargoTrain()
{
	weight = 2125;
	height = 4;
	LoadCapacity = 0;
	wagons = 85;
}

TCargoTrain::TCargoTrain(int _LoadCapacity): TCargoTrain()
{
	SetLoadCapacity(_LoadCapacity);
}

TCargoTrain::TCargoTrain(const TCargoTrain& p) : TRailroad()
{
	LoadCapacity = p.LoadCapacity;
}

void TCargoTrain::SetLoadCapacity(int _LoadCapacity)
{
	if (_LoadCapacity >= 0) this->LoadCapacity = _LoadCapacity;
	else std::cout << "Wrong argument" << std::endl;
}

int TCargoTrain::GetLoadCapacity()
{
	return LoadCapacity;
}
void TCargoTrain::Print()
{
	std::cout << "Cargo Train\n" << "Weight = " << GetWeight() << " tonns\n" << "Height = " << GetHeight() <<
	" meters\n" << "Wagons = " << GetWagons() << "\n" << "Load Capacity = " << GetLoadCapacity() <<
	" tonns\n" << std::endl;
}
