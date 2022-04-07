#pragma once
#include "Railroad.h"
class TPass: public TRailroad
{
public:
	TPass();
	TPass(int _maxpassengers);
	TPass(const TPass& p);
	void SetMaxPassengers(int _maxpassengers);
	int GetMaxPassengers();
	void Print() override;
private:
	int maxpassengers;
};