#pragma once
#include<string>
using std::string;
class vehicle
{
public:
	enum mode  //基本维护费
	{
		car_fee = 1000, //1000
		bus_fee = 2000, //2000
		truck_fee = 1500  //1500
	};
protected:          /*车辆基本信息*/
	string ID;      //车辆编号
	string Company; //车辆制造公司
	string data;    //购买时间
	string model;   //型号
	string type;    //车辆类型
	double total_cost;  //总费用
public:
	vehicle();
	vehicle(string &id_m, string &company_m, string &data_m, string &model_m,string &type_m);
	vehicle(string &id_m, string &company_m, string &data_m, string &model_m, string &type_m, double tcost);
	~vehicle();
	vehicle *next;
	string get_ID(void) { return ID; }
	string get_Company(void) { return Company; }
	string get_data(void) { return data; }
	string get_model(void) { return model; }
	string get_type(void) { return type; }
	double get_tcost(void) { return total_cost; }
	virtual void set_tdistance(double) = 0;  //纯虚函数
	virtual void set_tcost(void) = 0;
	void display(void);
};
