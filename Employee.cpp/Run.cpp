#include<iostream>
#include"workManager.h"
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
using namespace std;

//int main()
//{
//	 
//	workManager wm;
//	//Worker *w = NULL;
//	//w = new Employee(1,"张三",1);
//	//w->showInfo();
//	//delete w;
//	//Manager *m = NULL;
//	//m = new Manager(2, "qq", 2);
//	//m->showInfo();
//	//delete m;
//	//Boss *b = NULL;
//	//b = new Boss(3, "ew", 3);
//	//b->showInfo();
//	//delete b;
//
//	int choose = 0;
//	while (true)
//	{
//		wm.showMeau();
//		cout << "请输入要进行的操作！" << endl;
//		cin >> choose;
//
//		switch (choose)
//		{
//		case 0:
//			wm.Exit();
//			break;
//		case 1:
//			wm.Add();
//			break;
//		case 2:
//			wm.showPerosn();
//			break;
//		case 3:
//			wm.deletePerson();
//			break;
//		case 4:
//			wm.Correct();
//			break;
//		case 5:
//			wm.FindPerson();
//			break;
//		case 6:
//			wm.IdSort();
//			break;
//		case 7:
//			wm.clean();
//			break;
//		default:
//			system("cls");
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}