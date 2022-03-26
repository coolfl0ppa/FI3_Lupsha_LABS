#include "Railroad.h"
#include <iostream>
TRailroad::TRailroad()
{
	wagons = 0;
}
TRailroad::TRailroad(int _wagons): TRailroad()
{
	SetWagons(_wagons);
}

TRailroad::TRailroad(const TRailroad& p): TTransport()
{
	wagons = p.wagons;
}
void TRailroad::SetWagons(int _wagons)
{
	if (_wagons >= 0) this->wagons = _wagons;
	else std::cout << "Wrong argument" << std::endl;
}


int TRailroad::GetWagons()
{
	return wagons;
}