#pragma once
#include "Transport.h"
#include <iostream>
class TAir: public TTransport
{
public:
	TAir();
	TAir(int _maxaltitude);
	TAir(const TAir& p);
	void SetMaxAltitude(int _maxaltitude);
	int GetMaxAltitude();
protected:
	int maxaltitude;
};
