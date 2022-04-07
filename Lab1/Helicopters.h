#pragma once
#include "Air.h"
class THelicopters : public TAir
{
public:
	THelicopters();
	THelicopters(int _blades);
	THelicopters(const THelicopters& p);
	void SetBlades(int _blades);
	int GetBlades();
	void Print() override;
private:
	int blades;
};