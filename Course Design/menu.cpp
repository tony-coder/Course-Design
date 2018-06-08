#include"menu.h"
using namespace std;
void menu()
{
	system("color 0b");
	cout << endl << endl << endl;
	cout << "                 --------------主菜单--------------" << endl;
	cout << endl;
	cout << "                       1.车辆信息管理系统" << endl;
	cout << endl;
	cout << "                       0.退出" << endl;
	cout << endl;
	cout << "                       请输入您的操作:";
	int num;
	for (cin >> num; num != 1 && num != 0; cin >> num)
	{
		cout << "对不起，您只能输入1或0，请重新输入!" << endl;
		cin.clear();
		while (cin.get() != '\n')  //去除错误输入
			continue;
	}
	switch (num)
	{
	case 1:
		login();
	break;
	case 0:
		exit(0);
	default:
		break;
	}
}
void login()  //测试中！！！！
{
	int num, judge;
	int outside_loop = 1;  //外循环
	int inner_loop;  //内循环
	string id;
	management c;
	while (outside_loop)
	{
		system("color 0e");
		system("cls");
		cout << "\n          --------------------车辆信息管理系统--------------------\n" << endl;
		cout << "           1:增加车辆信息                              2:修改车辆信息 " << endl;
		cout << "\n";
		cout << "           3:修改车辆的当月公里数                      4:删除车辆信息 " << endl;
		cout << "\n";
		cout << "           5:查找车辆信息                              6:简单统计信息" << endl;
		cout << "\n";
		cout << "           7:将数据写入磁盘                            8:从磁盘读取数据" << endl;
		cout << '\n';
		cout << "           9:清空内存                                  0:返回上一级" << endl;
		inner_loop = 1;
		while (inner_loop)
		{
			cout << "                              请选择操作(0-9):";
			num = -1;  //重置num
			for (cin >> num; num < 0 || num>9; cin >> num)
			{
				cout << "对不起，您只能从0-9中选择输入，请重新输入!" << endl;
				cin.clear();
				while (cin.get() != '\n')  //去除错误输入
					continue;
			}

			system("cls");
			switch (num)
			{
			case 1:
				cout << "************增加车辆信息************\n";
				while (1)
				{
					c.add();
					cout << "希望继续输入? 1:继续 0:返回上一级\n";
					judge = enter_correct();  //判断输入是否正确
					if (judge == 0)
						break;
				}
				inner_loop = 0;
				break;
			case 2:
				cout << "************修改车辆信息************\n";
				while (1)
				{
					cout << "请输入您要修改的车辆编号:";
					cin.get();  //去除换行符
					getline(cin, id);
					if (c.modify(id))
					{
						cout << "希望继续修改? 1:继续 0:返回上一级\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
					else
					{
						cout << "是否要重新输入?1:是的 0:返回上一级\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
				}
				inner_loop = 0;
				break;
			case 3:
				cout << "***********车辆的当月公里数***********\n";
				while (1)
				{
					cout << "请输入您要修改的车辆编号:";
					cin.get();  //去除换行符
					getline(cin, id);
					if (c.modify_distance(id))
					{
						cout << "希望继续修改? 1:继续 0:返回上一级\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
					else
					{
						cout << "是否要重新输入?1:是的 0:返回上一级\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
				}
				inner_loop = 0;
				break;
			case 4:
				cout << "************删除车辆信息************\n";
				while (1)
				{
					cout << "请输入您要删除的车辆编号:";
					cin.get();  //去除换行符
					getline(cin, id);
					if (c.remove(id))
					{
						cout << "希望继续删除? 1:继续 0:返回上一级\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
					else
					{
						cout << "是否要重新输入?1:是的 0:返回上一级\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
				}
				inner_loop = 0;
				break;
			case 5:
				cout << "************查找车辆信息************\n";
				while (1)
				{
					cout << "请输入您要查找的车辆编号:";
					cin.get();  //去除换行符
					getline(cin, id);
					vehicle * temp;
					if (temp = c.find(id))
					{
						temp->display();
						cout << "希望继续查找? 1:继续 0:返回上一级\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
					else
					{
						cout << "是否要重新输入?1:是的 0:返回上一级\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
				}
				inner_loop = 0;
				break;
			case 6:
				cout << "************简单统计信息************\n";
				c.statistics();
				cout << "按任意键返回上一级\n";
				cin.get();
				cin.get();

				inner_loop = 0;
				break;
			case 7:
				cout << "***********将数据写入磁盘************\n";
				if (c.write())
				{
					cout << "储存成功!数据已储存在Data.txt\n";
					cout<< "按任意键返回上一级";
					cin.get();
					cin.get();
					inner_loop = 0;
					break;
				}
				else
				{
					cout << "ERROR!写入失败!请重试\n";
					cout<< "按任意键返回上一级";
					cin.get();
					cin.get();
					inner_loop = 0;
					break;
				}
			case 8:
				cout << "***********从磁盘读取数据************\n";
				c.read();
				cout << "读取成功!" << endl;
				c.display();
				cout << "按任意键返回上一级";
				cin.get();
				cin.get();
				inner_loop = 0;
				break;
			case 9:
				c.clear();
				cout << "清除成功!\n";
				cout << "按任意键返回上一级";
				cin.get();
				cin.get();
				inner_loop = 0;
				break;
			case 0:
				inner_loop = 0;
				outside_loop = 0;
				c.clear();  //清空内存
				break;
			default:
				break;
			}
		}
	}
}

int enter_correct(void) {
	int judge;
	for (cin >> judge; judge != 0 && judge != 1; cin >> judge)
	{
		cout << "对不起，您只能输入0或1，请重新输入!" << endl;
		cin.clear();
		while (cin.get() != '\n')  //去除错误输入
			continue;
	}
	return judge;
}