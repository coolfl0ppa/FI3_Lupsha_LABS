#include "Air.h"

TAir::TAir()
{
	maxaltitude = 0;
}

TAir::TAir(int _maxaltitude): TAir()
{
	SetMaxAltitude(_maxaltitude);
}

TAir::TAir(const TAir& p): TTransport()
{
	maxaltitude = p.maxaltitude;
}

void TAir::SetMaxAltitude(int _maxaltitude)
{
	if (_maxaltitude >= 0) this->maxaltitude = _maxaltitude;
	else std::cout << "Wrong argument" << std::endl;
}

int TAir::GetMaxAltitude()
{
	return maxaltitude;
}
