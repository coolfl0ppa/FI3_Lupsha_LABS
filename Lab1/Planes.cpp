#include "Planes.h"

Planes::Planes()
{
	wingspan = 60;
	maxaltitude = 13700;
	weight = 162;
	height = 20;
}

Planes::Planes(int _wingspan): Planes()
{
	SetWingSpan(_wingspan);
}

Planes::Planes(const Planes& p): TAir()
{
	wingspan = p.wingspan;
}

void Planes::SetWingSpan(int _wingspan)
{
	if (_wingspan >= 0) this->wingspan = _wingspan;
	else std::cout << "Wrong argument" << std::endl;
}

int Planes::GetWingSpan()
{
	return wingspan;
}

void Planes::Print()
{
	std::cout << "Plane\n" << "Weight = " << GetWeight() << " tonns\n" << "Height = " << GetHeight() <<
	" meters\n" << "Max altitude = " << GetMaxAltitude() << " meters\n" << "Wingspan = " << GetWingSpan() <<
	" meters" << std::endl;
}
