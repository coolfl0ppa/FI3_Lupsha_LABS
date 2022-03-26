#pragma once
#include "Transport.h"
class TRailroad: public TTransport
{
public:
	TRailroad();
	TRailroad(int _wagons);
	TRailroad(const TRailroad& p);
	void SetWagons(int _wagons);
	int GetWagons();
protected:
	int wagons;
};
