#pragma once
#include "Air.h"
class Planes: public TAir
{
public:
	Planes();
	Planes(int _wingspan);
	Planes(const Planes& p);
	void SetWingSpan(int _wingspan);
	int GetWingSpan();
	void Print() override;
private:
	int wingspan;
};
