#include "Bus.h"



Bus::Bus()
{
	total_distance = 0.0;
	Fuel_consumption = 0.0;
	Base_maintain_fee = bus_fee;
	Road_maintenance_fee = 0.0;
}
Bus::Bus(string &ID_m, string &company_m, string &data_m, string &model_m, string &type_m
	, double td, double fuel, double road) :vehicle(ID_m, company_m, data_m, model_m, type_m)
{
	total_distance = td;
	Fuel_consumption = fuel;
	Base_maintain_fee = bus_fee;;
	Road_maintenance_fee = road;
	set_tcost();
}
Bus::Bus(string &ID_m, string &company_m, string &data_m, string &model_m, string &type_m, double tcost) :vehicle(ID_m, company_m, data_m, model_m, type_m, tcost) {}

Bus::~Bus()
{
}
