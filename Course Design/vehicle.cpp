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
	std::cout << "���: " << ID<<" "<< "�������칫˾: " << Company<<" " << "����ʱ��: " << data <<" "<< "�ͺ�: " << model<<" "
		<< "��������: " << type <<" "<< "�ۼ��ܷ���: " << total_cost << std::endl;
}
