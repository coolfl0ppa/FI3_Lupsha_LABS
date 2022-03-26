#include <iostream>
#include "Transport.h"
#include "Air.h"
#include "Railroad.h"
#include "Planes.h"
#include "Helicopters.h"
#include "CargoTrain.h"
#include "PassengerTrain.h"
using namespace std;
inline void skip() {
	cout << endl;
}
int main()
{
	TTransport* Boeing_747_100 = new Planes();
	Boeing_747_100->Print();
	skip();
	TTransport* MI_38 = new THelicopters();
	MI_38->Print();
	skip();
	TCargoTrain NumberOne(5100);
	NumberOne.Print();
	skip();
	TPass Peregrine(592);
	Peregrine.Print();
	skip();
	return 0;

}
