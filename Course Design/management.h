#pragma once
#include"vehicle.h"

class management
{
public:
	management();
	~management();
	bool add(void);  //添加
	void display(void);  //显示
	int IsLast(vehicle * p) { return p->next == NULL; }  //测试当前位置是否是链表末尾
	vehicle * find(string &);  //查找
	vehicle * findPrevious(string &);  //查找前驱元
	bool remove(string &);  //删除
	void insert(vehicle &, string &);  //插入
	void clear(void);       //清空内存
	bool modify(string &);  //修改
	bool modify_distance(string &);  //修改公里数
	void statistics();  //统计信息
	bool write(const string & address = "D://management.txt");  //写入文件 默认为D://management.txt
	bool read(const string & address = "D://management.txt");   //读取文件 默认为D://management.txt

protected:  //内部使用
	void swap(vehicle *, vehicle *);  //交换两个成员
	void sort();  //排序(从大到小)

private:
	vehicle * head = NULL;  //表头
	vehicle * prev;  //储存上一个节点指针
};

