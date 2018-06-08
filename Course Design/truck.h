#pragma once
#include "vehicle.h"
class truck :
	public vehicle
{
public:
	truck();
	truck(string &ID_m, string &company_m, string &data_m, string &model_m, string &type_m, double td, double fuel, double road);
	truck(string &ID_m, string &company_m, string &data_m, string &model_m, string &type_m, double tcost);
	~truck();
	//truck *next;
	virtual void set_tcost(void) { total_cost = total_distance * Fuel_consumption + Base_maintain_fee + Road_maintenance_fee; }
	virtual void set_tdistance(double d) { total_distance = d; }
protected:
	double total_distance;    //总公里数
	double Fuel_consumption;  //耗油量
	double Base_maintain_fee; //基本维护费
	double Road_maintenance_fee;  //养路费
};

