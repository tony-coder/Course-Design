#include"menu.h"
using namespace std;
void menu()
{
	system("color 0b");
	cout << endl << endl << endl;
	cout << "                 --------------���˵�--------------" << endl;
	cout << endl;
	cout << "                       1.������Ϣ����ϵͳ" << endl;
	cout << endl;
	cout << "                       0.�˳�" << endl;
	cout << endl;
	cout << "                       ���������Ĳ���:";
	int num;
	for (cin >> num; num != 1 && num != 0; cin >> num)
	{
		cout << "�Բ�����ֻ������1��0������������!" << endl;
		cin.clear();
		while (cin.get() != '\n')  //ȥ����������
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
void login()  //�����У�������
{
	int num, judge;
	int outside_loop = 1;  //��ѭ��
	int inner_loop;  //��ѭ��
	string id;
	management c;
	while (outside_loop)
	{
		system("color 0e");
		system("cls");
		cout << "\n          --------------------������Ϣ����ϵͳ--------------------\n" << endl;
		cout << "           1:���ӳ�����Ϣ                              2:�޸ĳ�����Ϣ " << endl;
		cout << "\n";
		cout << "           3:�޸ĳ����ĵ��¹�����                      4:ɾ��������Ϣ " << endl;
		cout << "\n";
		cout << "           5:���ҳ�����Ϣ                              6:��ͳ����Ϣ" << endl;
		cout << "\n";
		cout << "           7:������д�����                            8:�Ӵ��̶�ȡ����" << endl;
		cout << '\n';
		cout << "           9:����ڴ�                                  0:������һ��" << endl;
		inner_loop = 1;
		while (inner_loop)
		{
			cout << "                              ��ѡ�����(0-9):";
			num = -1;  //����num
			for (cin >> num; num < 0 || num>9; cin >> num)
			{
				cout << "�Բ�����ֻ�ܴ�0-9��ѡ�����룬����������!" << endl;
				cin.clear();
				while (cin.get() != '\n')  //ȥ����������
					continue;
			}

			system("cls");
			switch (num)
			{
			case 1:
				cout << "************���ӳ�����Ϣ************\n";
				while (1)
				{
					c.add();
					cout << "ϣ����������? 1:���� 0:������һ��\n";
					judge = enter_correct();  //�ж������Ƿ���ȷ
					if (judge == 0)
						break;
				}
				inner_loop = 0;
				break;
			case 2:
				cout << "************�޸ĳ�����Ϣ************\n";
				while (1)
				{
					cout << "��������Ҫ�޸ĵĳ������:";
					cin.get();  //ȥ�����з�
					getline(cin, id);
					if (c.modify(id))
					{
						cout << "ϣ�������޸�? 1:���� 0:������һ��\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
					else
					{
						cout << "�Ƿ�Ҫ��������?1:�ǵ� 0:������һ��\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
				}
				inner_loop = 0;
				break;
			case 3:
				cout << "***********�����ĵ��¹�����***********\n";
				while (1)
				{
					cout << "��������Ҫ�޸ĵĳ������:";
					cin.get();  //ȥ�����з�
					getline(cin, id);
					if (c.modify_distance(id))
					{
						cout << "ϣ�������޸�? 1:���� 0:������һ��\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
					else
					{
						cout << "�Ƿ�Ҫ��������?1:�ǵ� 0:������һ��\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
				}
				inner_loop = 0;
				break;
			case 4:
				cout << "************ɾ��������Ϣ************\n";
				while (1)
				{
					cout << "��������Ҫɾ���ĳ������:";
					cin.get();  //ȥ�����з�
					getline(cin, id);
					if (c.remove(id))
					{
						cout << "ϣ������ɾ��? 1:���� 0:������һ��\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
					else
					{
						cout << "�Ƿ�Ҫ��������?1:�ǵ� 0:������һ��\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
				}
				inner_loop = 0;
				break;
			case 5:
				cout << "************���ҳ�����Ϣ************\n";
				while (1)
				{
					cout << "��������Ҫ���ҵĳ������:";
					cin.get();  //ȥ�����з�
					getline(cin, id);
					vehicle * temp;
					if (temp = c.find(id))
					{
						temp->display();
						cout << "ϣ����������? 1:���� 0:������һ��\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
					else
					{
						cout << "�Ƿ�Ҫ��������?1:�ǵ� 0:������һ��\n";
						judge = enter_correct();
						if (judge == 0)
							break;
					}
				}
				inner_loop = 0;
				break;
			case 6:
				cout << "************��ͳ����Ϣ************\n";
				c.statistics();
				cout << "�������������һ��\n";
				cin.get();
				cin.get();

				inner_loop = 0;
				break;
			case 7:
				cout << "***********������д�����************\n";
				if (c.write())
				{
					cout << "����ɹ�!�����Ѵ�����Data.txt\n";
					cout<< "�������������һ��";
					cin.get();
					cin.get();
					inner_loop = 0;
					break;
				}
				else
				{
					cout << "ERROR!д��ʧ��!������\n";
					cout<< "�������������һ��";
					cin.get();
					cin.get();
					inner_loop = 0;
					break;
				}
			case 8:
				cout << "***********�Ӵ��̶�ȡ����************\n";
				c.read();
				cout << "��ȡ�ɹ�!" << endl;
				c.display();
				cout << "�������������һ��";
				cin.get();
				cin.get();
				inner_loop = 0;
				break;
			case 9:
				c.clear();
				cout << "����ɹ�!\n";
				cout << "�������������һ��";
				cin.get();
				cin.get();
				inner_loop = 0;
				break;
			case 0:
				inner_loop = 0;
				outside_loop = 0;
				c.clear();  //����ڴ�
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
		cout << "�Բ�����ֻ������0��1������������!" << endl;
		cin.clear();
		while (cin.get() != '\n')  //ȥ����������
			continue;
	}
	return judge;
}