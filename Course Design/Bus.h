#pragma once
#include "vehicle.h"
class Bus :
	public vehicle
{
public:
	Bus();
	Bus(string &ID_m, string &company_m, string &data_m, string &model_m, string &type_m, double td, double fuel, double road);
	Bus(string &ID_m, string &company_m, string &data_m, string &model_m, string &type_m, double tcost);
	~Bus();
	Bus *next;
	virtual void set_tcost(void) { total_cost = total_distance * Fuel_consumption + Base_maintain_fee + Road_maintenance_fee; }
	virtual void set_tdistance(double d) { total_distance = d; }
protected:
	double total_distance;    //�ܹ�����
	double Fuel_consumption;  //������
	double Base_maintain_fee; //����ά����
	double Road_maintenance_fee;  //��·��
};

