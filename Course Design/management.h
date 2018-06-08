#pragma once
#include"vehicle.h"

class management
{
public:
	management() :head(NULL) {}
	~management();
	bool add(void);  //���
	void display(void);  //��ʾ
	int IsLast(vehicle * p) { return p->next == NULL; }  //���Ե�ǰλ���Ƿ�������ĩβ
	vehicle * find(string &);  //����
	vehicle * findPrevious(string &);  //����ǰ��Ԫ
	bool remove(string &);  //ɾ��
	//void insert(vehicle &, string &);  //����
	void clear(void);       //����ڴ�
	bool modify(string &);  //�޸�
	bool modify_distance(string &);  //�޸Ĺ�����
	void statistics();  //ͳ����Ϣ
	bool write(const string & address = "Data.txt");  //д���ļ�
	bool read(const string & address = "Data.txt");   //��ȡ�ļ�

protected:  //�ڲ�ʹ��
	void swap(vehicle *, vehicle *);  //����������Ա
	void sort();  //����(�Ӵ�С)

private:
	vehicle * head;  //��ͷ
	vehicle * prev;  //������һ���ڵ�ָ��
};

