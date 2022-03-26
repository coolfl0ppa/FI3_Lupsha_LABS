#pragma once
#include "Railroad.h"
class TCargoTrain: public TRailroad
{
public:
	TCargoTrain();
	TCargoTrain(int _LoadCapacity);
	TCargoTrain(const TCargoTrain& p);
	void SetLoadCapacity(int _LoadCapacity);
	int GetLoadCapacity();
	void Print() override;
private:
	int LoadCapacity;
};
