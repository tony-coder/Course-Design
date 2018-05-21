#include "management.h"
#include"vehicle.h"
#include"Car.h"
#include"Bus.h"
#include"truck.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
management::management()
{
}


management::~management()
{
}

bool management::add(void) {
	vehicle * current;
	string ID;      //车辆编号
	string Company; //车辆制造公司
	string data;    //购买时间
	string model;   //型号
	string type;    //车辆类型
	int type_t;   
	double total_distance;    //总公里数
	double Fuel_consumption;  //耗油量
	double Road_maintenance_fee;  //养路费
	
	cin.get();  //去除换行符

	cout << "请输入车辆编号: ";
	getline(cin, ID);
	cout << "请输入车辆制造公司: ";
	getline(cin, Company);
	cout << "请输入购买时间: ";
	getline(cin, data);
	cout << "请输入型号: ";
	getline(cin, model);
	cout << "请输入车辆种类(1: 客车  2: 小轿车  3: 卡车): ";
	cin >> type_t;
	/**************错误处理****************/
	while (type_t != 1 && type_t != 2 && type_t != 3)
	{
		cout << "输入有误！你只能从（1: 客车  2: 小轿车  3: 卡车）中选择数字输入 " << "请重试！" << endl;
		cin.clear();
		while (cin.get() != '\n')  //去除错误输入
			continue;
		cin >> type_t;
	}
	
	cout << "请输入总公里数: ";
	cin >> total_distance;
	cout << "请输入耗油量: ";
	cin >> Fuel_consumption;
	cout << "请输入养路费: ";
	cin >> Road_maintenance_fee;

	cin.get();   //去除换行符
	
	switch (type_t)
	{
	case 1:
		type = "客车";
		current = new Bus(ID, Company, data, model, type, total_distance, Fuel_consumption, Road_maintenance_fee);
		if (head == NULL)
		{
			head = new Bus();    //head:表头，位置为0，空表
			head->next = current;
		}
		else
			prev->next = current;
		current->next = NULL;
		prev = current;
		cout << "添加成功！" << endl;
		return true;
	case 2:
		type = "小轿车";
		current = new Car(ID, Company, data, model, type, total_distance, Fuel_consumption, Road_maintenance_fee);
		if (head == NULL)
		{
			head = new Bus();
			head->next = current;
		}
		else
			prev->next = current;
		current->next = NULL;
		prev = current;
		cout << "添加成功！" << endl;
		return true;
	case 3:
		type = "卡车";
		current = new truck(ID, Company, data, model, type, total_distance, Fuel_consumption, Road_maintenance_fee);
		if (head == NULL)
		{
			head = new Bus();
			head->next = current;
		}
		else
			prev->next = current;
		current->next = NULL;
		prev = current;
		cout << "添加成功！" << endl;
		return true;
	default:
		cout << "添加失败";
		break;
	}
	return false;
}

void management::display() {
	if (head)
	{
		for (vehicle * pn = head->next; pn; pn = pn->next)
			pn->display();
	}
}

vehicle* management::find(string & f) {
	/*vehicle *pd = head;
	while (pd != NULL && pd->get_ID() != f)
		pd = pd->next;
	return pd;*/
	if (head)  //判断表头是否为空
	{
		for (vehicle *pd = head->next; pd; pd = pd->next)
		{
			if (pd->get_ID() == f)
				return pd;
		}
	}
	cout << "ERROR!未找到成员" << endl;
	return NULL;
}

vehicle * management::findPrevious(string & f) {
	if (head)
	{
		for (vehicle *pd = head; pd->next; pd = pd->next)
		{
			if (pd->next->get_ID() == f)
				return pd;
		}
	}
	return NULL;
}

bool management::remove(string &r) {
	vehicle * p;
	vehicle * d;
	if (p=findPrevious(r))
	{
		d = p->next;
		if (!IsLast(p->next))  //是否在末尾
		{
			vehicle *temp = p->next;
			p->next = temp->next;
			delete d;  //清空内存
		}
		else
		{
			vehicle *temp = p->next;
			p->next = temp->next;
			prev = p;
			delete d;  //清空内存
		}
		cout << "删除成功!";
		return true;
	}
	else
		cout<<"ERROR!未找到成员"<<endl;
	return false;
}
void management::clear() {
	if (head != NULL)
	{
		vehicle * p = head->next;
		vehicle * temp;
		while (p)
		{
			temp = p->next;
			delete p;
			p = temp;
		}
		head->next = NULL;
		prev = head;
	}
}

bool management::modify(string & s) {
	vehicle * current;
	string ID;
	string Company;
	string data;
	string model;
	string type;
	int type_t;
	double total_distance;
	double Fuel_consumption;
	double Road_maintenance_fee;

	vehicle *node;
	if (node=findPrevious(s))  //找到该节点
	{
		cout << "请输入新的车辆编号: ";
		getline(cin, ID);
		cout << "请输入新的车辆制造公司: ";
		getline(cin, Company);
		cout << "请输入新的购买时间: ";
		getline(cin, data);
		cout << "请输入新的型号: ";
		getline(cin, model);
		cout << "请输入新的车辆种类(1: 客车  2: 小轿车  3: 卡车): ";
		cin >> type_t;
		/**************错误处理****************/
		while (type_t != 1 && type_t != 2 && type_t != 3)
		{
			cout << "输入有误！你只能从（1: 客车  2: 小轿车  3: 卡车）中选择数字输入 " << "请重试！" << endl;
			cin.clear();
			while (cin.get() != '\n')  //去除错误输入
				continue;
			cin >> type_t;
		}
		cout << "请输入新的总公里数: ";
		cin >> total_distance;
		cout << "请输入新的耗油量: ";
		cin >> Fuel_consumption;
		cout << "请输入新的养路费: ";
		cin >> Road_maintenance_fee;
		cin.get();   //去除换行符
		switch (type_t)
		{
		case 1:
			type = "客车";
			current = new Bus(ID, Company, data, model, type, total_distance, Fuel_consumption, Road_maintenance_fee);
			current->next = node->next->next;
			node->next = current;
			cout << "修改成功！" << endl;
			return true;
		case 2:
			type = "小轿车";
			current = new Car(ID, Company, data, model, type, total_distance, Fuel_consumption, Road_maintenance_fee);
			current->next = node->next->next;
			node->next = current;
			cout << "修改成功！" << endl;
			return true;
		case 3:
			type = "卡车";
			current = new truck(ID, Company, data, model, type, total_distance, Fuel_consumption, Road_maintenance_fee);
			current->next = node->next->next;
			node->next = current;
			cout << "修改成功！" << endl;
			return true;
		default:
			break;
		}
	}
	cout << "ERROR!未找到成员" << endl;
	return false;
}

bool management::modify_distance(string & s) {
	double total_distance;    //总公里数
	vehicle * node;
	if (node = find(s))
	{
		cout << "请输入新的总公里数: ";
		cin >> total_distance;
		node->set_tdistance(total_distance);
		node->set_tcost();  //修改总费用
		return true;
	}
	cout << "ERROR!未找到成员" << endl;
	return false;
}

void management::swap(vehicle * a, vehicle *b) {  //交换节点
	vehicle *c, *d;
	for (c = head; c->next; c = c->next)
	{
		if (c->next == a)
			break;
	}
	for (d = head; d->next; d = d->next)
	{
		if (d->next == b)
			break;
	}
	if (a == d && c->next != NULL)  //相邻节点交换
	{
		c->next = b;
		a->next = b->next;
		b->next = a;
	}
	else if (a != d && c->next != NULL && d->next != NULL)  //未相邻节点交换
	{
		vehicle *temp;
		c->next = b;
		temp = a->next;
		a->next = b->next;
		b->next = temp;
		d->next = a;
		c->next = b;
	}
}

void management::sort() {
	int count = 0;
	if (head)  //表头不为空
	{
		for (vehicle * temp = head->next; temp; temp = temp->next)  //得到链表的长度
			count++;

		for (int i = 0; i < count; i++)
		{
			vehicle *p = head->next;
			for (int j = 0; j < i; j++)
				p = p->next;    //令p始终指向第i+1位
			for (vehicle * s = p->next; s; s = s->next)
			{
				if (p->get_tcost()<s->get_tcost())
				{
					swap(p, s);
					s = p;  //校正s指针指向的位置
				}
				p = head->next;  //重新初始化p
				for (int j = 0; j < i; j++)
					p = p->next;    //令p始终指向第i+1位
			}
		}
		vehicle *last;
		for (last = head; last->next; last = last->next);
		prev = last;
	}
}

void management::statistics() {
	int  num;
	cout << "1:统计某类型所有车辆累计费用统计情况\n";
	cout << "2:按照某类车辆的累计总费用的高低进行排序\n";
	cout << "请选择操作:";
	cin >> num;
	
	if (num==1)
	{
		cout << "请输入车辆类型(1: 客车  2: 小轿车  3: 卡车)\n";
		int num;
		cin >> num;
		while (num != 1 && num != 2 && num != 3)
		{
			cout << "输入有误！你只能从（1: 客车  2: 小轿车  3: 卡车）中选择数字输入 " << "请重试！" << endl;
			cin.clear();
			while (cin.get() != '\n')  //去除错误输入
				continue;
			cin >> num;
		}
		string type;
		switch (num)
		{
		case 1:
			type = "客车";
			break;
		case 2:
			type = "小轿车";
			break;
		case 3:
			type = "卡车";
			break;
		}
		double sum = 0.0;
		for (vehicle *pd = head; pd; pd = pd->next)  //类型查找
		{
			if (pd->get_type() == type)
			{
				pd->display();
				sum += pd->get_tcost();
			}
		}
		cout << type << "类型车辆总费用为：" << sum << endl;
	}
	if (num==2)
	{
		sort();  //排序
		cout << "请输入车辆类型(1: 客车  2: 小轿车  3: 卡车)\n";
		int num;
		cin >> num;
		while (num != 1 && num != 2 && num != 3)
		{
			cout << "输入有误！你只能从（1: 客车  2: 小轿车  3: 卡车）中选择数字输入 " << "请重试！" << endl;
			cin >> num;
		}
		string type;
		switch (num)
		{
		case 1:
			type = "客车";
			break;
		case 2:
			type = "小轿车";
			break;
		case 3:
			type = "卡车";
			break;
		}
		int sum = 0;
		for (vehicle *pd = head; pd; pd = pd->next)  //类型查找
		{
			if (pd->get_type() == type)
				pd->display();
		}
	}
}

bool management::write(const string & address) {
	ofstream outFile;
	outFile.open(address);
	if (head)
	{
		for (vehicle *temp = head->next; temp; temp = temp->next)
			outFile << temp->get_ID() << "    " << temp->get_Company() << "    " << temp->get_data() << "    " << temp->get_model() << "    "
			<< temp->get_type() << "    " << temp->get_tcost() << endl;
		outFile.close();
		return true;
	}
	outFile.close();
	return false;
}

bool management::read(const string & address) {
	ifstream inFile;
	inFile.open(address);
	string ID;
	string Company;
	string data;
	string model;
	string type;
	double total_cost;
	clear();  //清空内存
	inFile >> ID >> Company >> data >> model >> type >> total_cost;
	while (inFile.good())
	{
		vehicle *current;
		if (type=="客车")
		{
			current = new Bus(ID, Company, data, model,type, total_cost);
			if (head == NULL)
			{
				head = new Bus();    //head:表头，位置为0，空表
				head->next = current;
			}
			else
				prev->next = current;
			current->next = NULL;
			prev = current;
		}
		else if (type == "小轿车")
		{
			current = new Car(ID, Company, data, model, type, total_cost);
			if (head == NULL)
			{
				head = new Car();    //head:表头，位置为0，空表
				head->next = current;
			}
			else
				prev->next = current;
			current->next = NULL;
			prev = current;
		}
		else if (type == "卡车")
		{
			current = new truck(ID, Company, data, model, type, total_cost);
			if (head == NULL)
			{
				head = new truck();    //head:表头，位置为0，空表
				head->next = current;
			}
			else
				prev->next = current;
			current->next = NULL;
			prev = current;
		}
		inFile >> ID >> Company >> data >> model >> type >> total_cost;
	}
	return true;
}