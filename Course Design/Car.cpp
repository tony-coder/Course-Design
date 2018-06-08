#include "Car.h"


Car::Car()
{
	
}
Car::Car(string &ID_m, string &company_m, string &data_m, string &model_m, string &type_m
	, double td, double fuel, double road) :vehicle(ID_m, company_m, data_m, model_m, type_m)
{
	total_distance = td;
	Fuel_consumption = fuel;
	Base_maintain_fee = car_fee;
	Road_maintenance_fee = road;
	set_tcost();
}

Car::Car(string &ID_m, string &company_m, string &data_m, string &model_m, string &type_m, double tcost) :vehicle(ID_m, company_m, data_m, model_m, type_m, tcost) {}


Car::~Car()
{
}