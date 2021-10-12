#include "pch.h"
#include "MultiVehicle.h"

list<Vehicle^>::generic_container^ MultiVehicle::getvehicle()
{
	Vehicle^ vehicle = gcnew Vehicle();
	vehicles->push_back(vehicle);

	return vehicles;
}
