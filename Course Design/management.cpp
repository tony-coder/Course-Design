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
	string ID;      //�������
	string Company; //�������칫˾
	string data;    //����ʱ��
	string model;   //�ͺ�
	string type;    //��������
	int type_t;   
	double total_distance;    //�ܹ�����
	double Fuel_consumption;  //������
	double Road_maintenance_fee;  //��·��
	
	cin.get();  //ȥ�����з�

	cout << "�����복�����: ";
	getline(cin, ID);
	cout << "�����복�����칫˾: ";
	getline(cin, Company);
	cout << "�����빺��ʱ��: ";
	getline(cin, data);
	cout << "�������ͺ�: ";
	getline(cin, model);
	cout << "�����복������(1: �ͳ�  2: С�γ�  3: ����): ";
	cin >> type_t;
	/**************������****************/
	while (type_t != 1 && type_t != 2 && type_t != 3)
	{
		cout << "����������ֻ�ܴӣ�1: �ͳ�  2: С�γ�  3: ��������ѡ���������� " << "�����ԣ�" << endl;
		cin.clear();
		while (cin.get() != '\n')  //ȥ����������
			continue;
		cin >> type_t;
	}
	
	cout << "�������ܹ�����: ";
	cin >> total_distance;
	cout << "�����������: ";
	cin >> Fuel_consumption;
	cout << "��������·��: ";
	cin >> Road_maintenance_fee;

	cin.get();   //ȥ�����з�
	
	switch (type_t)
	{
	case 1:
		type = "�ͳ�";
		current = new Bus(ID, Company, data, model, type, total_distance, Fuel_consumption, Road_maintenance_fee);
		if (head == NULL)
		{
			head = new Bus();    //head:��ͷ��λ��Ϊ0���ձ�
			head->next = current;
		}
		else
			prev->next = current;
		current->next = NULL;
		prev = current;
		cout << "��ӳɹ���" << endl;
		return true;
	case 2:
		type = "С�γ�";
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
		cout << "��ӳɹ���" << endl;
		return true;
	case 3:
		type = "����";
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
		cout << "��ӳɹ���" << endl;
		return true;
	default:
		cout << "���ʧ��";
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
	if (head)  //�жϱ�ͷ�Ƿ�Ϊ��
	{
		for (vehicle *pd = head->next; pd; pd = pd->next)
		{
			if (pd->get_ID() == f)
				return pd;
		}
	}
	cout << "ERROR!δ�ҵ���Ա" << endl;
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
		if (!IsLast(p->next))  //�Ƿ���ĩβ
		{
			vehicle *temp = p->next;
			p->next = temp->next;
			delete d;  //����ڴ�
		}
		else
		{
			vehicle *temp = p->next;
			p->next = temp->next;
			prev = p;
			delete d;  //����ڴ�
		}
		cout << "ɾ���ɹ�!";
		return true;
	}
	else
		cout<<"ERROR!δ�ҵ���Ա"<<endl;
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
	if (node=findPrevious(s))  //�ҵ��ýڵ�
	{
		cout << "�������µĳ������: ";
		getline(cin, ID);
		cout << "�������µĳ������칫˾: ";
		getline(cin, Company);
		cout << "�������µĹ���ʱ��: ";
		getline(cin, data);
		cout << "�������µ��ͺ�: ";
		getline(cin, model);
		cout << "�������µĳ�������(1: �ͳ�  2: С�γ�  3: ����): ";
		cin >> type_t;
		/**************������****************/
		while (type_t != 1 && type_t != 2 && type_t != 3)
		{
			cout << "����������ֻ�ܴӣ�1: �ͳ�  2: С�γ�  3: ��������ѡ���������� " << "�����ԣ�" << endl;
			cin.clear();
			while (cin.get() != '\n')  //ȥ����������
				continue;
			cin >> type_t;
		}
		cout << "�������µ��ܹ�����: ";
		cin >> total_distance;
		cout << "�������µĺ�����: ";
		cin >> Fuel_consumption;
		cout << "�������µ���·��: ";
		cin >> Road_maintenance_fee;
		cin.get();   //ȥ�����з�
		switch (type_t)
		{
		case 1:
			type = "�ͳ�";
			current = new Bus(ID, Company, data, model, type, total_distance, Fuel_consumption, Road_maintenance_fee);
			current->next = node->next->next;
			node->next = current;
			cout << "�޸ĳɹ���" << endl;
			return true;
		case 2:
			type = "С�γ�";
			current = new Car(ID, Company, data, model, type, total_distance, Fuel_consumption, Road_maintenance_fee);
			current->next = node->next->next;
			node->next = current;
			cout << "�޸ĳɹ���" << endl;
			return true;
		case 3:
			type = "����";
			current = new truck(ID, Company, data, model, type, total_distance, Fuel_consumption, Road_maintenance_fee);
			current->next = node->next->next;
			node->next = current;
			cout << "�޸ĳɹ���" << endl;
			return true;
		default:
			break;
		}
	}
	cout << "ERROR!δ�ҵ���Ա" << endl;
	return false;
}

bool management::modify_distance(string & s) {
	double total_distance;    //�ܹ�����
	vehicle * node;
	if (node = find(s))
	{
		cout << "�������µ��ܹ�����: ";
		cin >> total_distance;
		node->set_tdistance(total_distance);
		node->set_tcost();  //�޸��ܷ���
		return true;
	}
	cout << "ERROR!δ�ҵ���Ա" << endl;
	return false;
}

void management::swap(vehicle * a, vehicle *b) {  //�����ڵ�
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
	if (a == d && c->next != NULL)  //���ڽڵ㽻��
	{
		c->next = b;
		a->next = b->next;
		b->next = a;
	}
	else if (a != d && c->next != NULL && d->next != NULL)  //δ���ڽڵ㽻��
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
	if (head)  //��ͷ��Ϊ��
	{
		for (vehicle * temp = head->next; temp; temp = temp->next)  //�õ�����ĳ���
			count++;

		for (int i = 0; i < count; i++)
		{
			vehicle *p = head->next;
			for (int j = 0; j < i; j++)
				p = p->next;    //��pʼ��ָ���i+1λ
			for (vehicle * s = p->next; s; s = s->next)
			{
				if (p->get_tcost()<s->get_tcost())
				{
					swap(p, s);
					s = p;  //У��sָ��ָ���λ��
				}
				p = head->next;  //���³�ʼ��p
				for (int j = 0; j < i; j++)
					p = p->next;    //��pʼ��ָ���i+1λ
			}
		}
		vehicle *last;
		for (last = head; last->next; last = last->next);
		prev = last;
	}
}

void management::statistics() {
	int  num;
	cout << "1:ͳ��ĳ�������г����ۼƷ���ͳ�����\n";
	cout << "2:����ĳ�೵�����ۼ��ܷ��õĸߵͽ�������\n";
	cout << "��ѡ�����:";
	cin >> num;
	
	if (num==1)
	{
		cout << "�����복������(1: �ͳ�  2: С�γ�  3: ����)\n";
		int num;
		cin >> num;
		while (num != 1 && num != 2 && num != 3)
		{
			cout << "����������ֻ�ܴӣ�1: �ͳ�  2: С�γ�  3: ��������ѡ���������� " << "�����ԣ�" << endl;
			cin.clear();
			while (cin.get() != '\n')  //ȥ����������
				continue;
			cin >> num;
		}
		string type;
		switch (num)
		{
		case 1:
			type = "�ͳ�";
			break;
		case 2:
			type = "С�γ�";
			break;
		case 3:
			type = "����";
			break;
		}
		double sum = 0.0;
		for (vehicle *pd = head; pd; pd = pd->next)  //���Ͳ���
		{
			if (pd->get_type() == type)
			{
				pd->display();
				sum += pd->get_tcost();
			}
		}
		cout << type << "���ͳ����ܷ���Ϊ��" << sum << endl;
	}
	if (num==2)
	{
		sort();  //����
		cout << "�����복������(1: �ͳ�  2: С�γ�  3: ����)\n";
		int num;
		cin >> num;
		while (num != 1 && num != 2 && num != 3)
		{
			cout << "����������ֻ�ܴӣ�1: �ͳ�  2: С�γ�  3: ��������ѡ���������� " << "�����ԣ�" << endl;
			cin >> num;
		}
		string type;
		switch (num)
		{
		case 1:
			type = "�ͳ�";
			break;
		case 2:
			type = "С�γ�";
			break;
		case 3:
			type = "����";
			break;
		}
		int sum = 0;
		for (vehicle *pd = head; pd; pd = pd->next)  //���Ͳ���
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
	clear();  //����ڴ�
	inFile >> ID >> Company >> data >> model >> type >> total_cost;
	while (inFile.good())
	{
		vehicle *current;
		if (type=="�ͳ�")
		{
			current = new Bus(ID, Company, data, model,type, total_cost);
			if (head == NULL)
			{
				head = new Bus();    //head:��ͷ��λ��Ϊ0���ձ�
				head->next = current;
			}
			else
				prev->next = current;
			current->next = NULL;
			prev = current;
		}
		else if (type == "С�γ�")
		{
			current = new Car(ID, Company, data, model, type, total_cost);
			if (head == NULL)
			{
				head = new Car();    //head:��ͷ��λ��Ϊ0���ձ�
				head->next = current;
			}
			else
				prev->next = current;
			current->next = NULL;
			prev = current;
		}
		else if (type == "����")
		{
			current = new truck(ID, Company, data, model, type, total_cost);
			if (head == NULL)
			{
				head = new truck();    //head:��ͷ��λ��Ϊ0���ձ�
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