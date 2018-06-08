#pragma once
#include<string>
using std::string;
class vehicle
{
public:
	enum mode  //����ά����
	{
		car_fee = 1000, //1000
		bus_fee = 2000, //2000
		truck_fee = 1500  //1500
	};
protected:          /*����������Ϣ*/
	string ID;      //�������
	string Company; //�������칫˾
	string data;    //����ʱ��
	string model;   //�ͺ�
	string type;    //��������
	double total_cost;  //�ܷ���
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
	virtual void set_tdistance(double) = 0;  //���麯��
	virtual void set_tcost(void) = 0;
	void display(void);
};
