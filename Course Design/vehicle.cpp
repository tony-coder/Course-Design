#include<iostream>
#include "vehicle.h"


vehicle::vehicle()
{
	
}
vehicle::vehicle(string &id_m,string &company_m,string &data_m,string &model_m,string &type_m){
	ID = id_m;
	Company = company_m;
	data = data_m;
	model = model_m;
	type = type_m;
}

vehicle::vehicle(string &id_m, string &company_m, string &data_m, string &model_m, string &type_m, double tcost) {
	ID = id_m;
	Company = company_m;
	data = data_m;
	model = model_m;
	type = type_m;
	total_cost = tcost;
}

vehicle::~vehicle()
{
}

void vehicle::display() {
	std::cout << "编号: " << ID<<" "<< "车辆制造公司: " << Company<<" " << "购买时间: " << data <<" "<< "型号: " << model<<" "
		<< "车辆种类: " << type <<" "<< "累计总费用: " << total_cost << std::endl;
}
