#include "Helicopters.h"

THelicopters::THelicopters()
{
	blades = 6;
	maxaltitude = 6000;
	weight = 10;
	height = 7;
}

THelicopters::THelicopters(int _blades): THelicopters()
{
	SetBlades(_blades);
}

THelicopters::THelicopters(const THelicopters& p): TAir()
{
	blades = p.blades;
}

void THelicopters::SetBlades(int _blades)
{
	if (_blades >= 0) this->blades = _blades;
	else std::cout << "Wrong argument" << std::endl;
}

int THelicopters::GetBlades()
{
	return blades;
}

void THelicopters::Print()
{
	std::cout << "Helicopter\n" << "Weight = " << GetWeight() << " tonns\n" << "Height = " << GetHeight() <<
	" meters\n" << "Max altitude = " << GetMaxAltitude() << " meters\n" << "Blades = " << GetBlades() <<
	std::endl;
}
