#pragma once
#include "Vehicle.h"
#include <cliext/list>

using namespace cliext;

public ref class MultiVehicle
{
public:
	list<Vehicle^>::generic_container ^vehicles;
	list<Vehicle^>::generic_container ^getvehicle();
	
};

 