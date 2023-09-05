#include<iostream>
#include<string>
#include<ctime>
using namespace std;

//若要后续更改联系人数量可方便进行维护
#define MAX 100

void menu()
{
	cout << "****************************" << endl;
	cout << "****   1.添加联系人！   ****" << endl;
	cout << "****   2.删除联系人！   ****" << endl;
	cout << "****   3.修改联系人！   ****" << endl;
	cout << "****   4.查找联系人！   ****" << endl;
	cout << "****   5.显示通讯录！   ****" << endl;
	cout << "****   6.清空通讯录！   ****" << endl;
	cout << "****   0.任意键退出！   ****" << endl;
	cout << "****************************" << endl;
}


struct person
{
	string name;
	string sex;
	int age;
	//long,int最多存放十位数字所以必须使用long long类型 
	long long int phone;
	string address;
};

struct Addressbook
{
	//通讯录结构数组保存每个人
	struct person Parry[MAX];
	int size;
};


//添加联系人
void Add(Addressbook *p)
{
	if (p->size == MAX)
	{
		cout << "通讯录已满，请删除后在进行添加！" << endl;
		return;
	}
	else
	{
		cout << "<----------系统提醒:如有同名则请加标识符予以区分---------->" << endl;
		//注意该模块并没有设置不允许同名，所以如果添加同名后，后续其他操作可能不一定全能实现(如:修改)，所以尽量加标识符予以区分
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		p->Parry[p->size].name = name;

		string sex;
		cout << "请输入性别:" << endl;
		while (true)
		{
			cin >> sex;
			if ((sex == "男") || (sex == "女"))
			{
				p->Parry[p->size].sex = sex;
				break;
			}
			else
			{
				cout << "输入有误,请重新输入！" << endl;
			}
		}
		

		int age;
		cout << "请输入年龄:" << endl;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				p->Parry[p->size].age = age;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入！注意:年龄范围[0,120]" << endl;
			}
		}

		long long int phone;
		cout << "请输入联系方式:" << endl;
		while (true)
		{
			cin >> phone;
			//除了判定号码长度以外喜欢的朋友还可以进行判定手机号是否正确(即是否有前三位这样开头的手机号)
			//亦或者是否存在相同手机号
			if (int(log10(phone) + 1)==11)//公式计算号码长度
			{
				p->Parry[p->size].phone = phone;
				break;
			}
			else
			{
				cout << "手机号码共十一位，请重新输入！" << endl;
			}
		}
		
		string address;
		cout << "请输入家庭住址:" << endl;
		cin >> address;
		p->Parry[p->size].address = address;

		//更新数组长度
		p->size++;
		cout << "系统提示:联系人成功添加！" << endl;
		//请按任意键继续
		system("pause");
		//清屏操作
		system("cls");
	}
}

//删除指定的联系人
void deletPerson(Addressbook *p)
{
	if(p->size==0)
	{
		cout << "联系人为空！" << endl;
	}
	else
	{
		string name;
		cout << "请输入要删除的联系人姓名:" << endl;
		cin >> name;
		for (int i = 0; i < p->size; i++)
		{
			if (name == p->Parry[i].name)
			{
				for (int j = i; j < p->size; j++)
				{
					p->Parry[j] = p->Parry[j + 1];//数据向前移动
				}
				p->size--;//删除之后更新数组的值
				cout << "系统提示:联系人删除成功！" << endl;
				break;
			}
			if((name != p->Parry[i].name) && (i == p->size-1))//已经查找完整个数组依然没有找到删除人的姓名
			{
				cout << "不存在该联系人!!!" << endl;
			}
		}
	}
	//请按任意键继续
	system("pause");
	//清屏操作
	system("cls");
}

//修改联系人
void CorrectPerson(Addressbook *p)
{
	if (p->size == 0)
	{
		cout << "通讯录为空！" << endl;
	}
	else
	{
		int CorArry[5];
		string name;
		string sex;
		int age;
		long long int phone;
		string address;
		cout << "请输入要修改的联系人姓名:" << endl;
		cin >> name;
		for (int i = 0; i < p->size; i++)
		{
			if (p->Parry[i].name == name)
			{
				cout << "修改前该联系人的所有信息为:" << endl;
				cout << "姓名:" << p->Parry[i].name << "\t";
				cout << "性别:" << p->Parry[i].sex << "\t";
				cout << "年龄:" << p->Parry[i].age << "\t";
				cout << "联系方式:" << p->Parry[i].phone << "\t";
				cout << "家庭住址:" << p->Parry[i].address << endl;
				//}
				cout << "请按姓名，性别，年龄，联系方式，家庭住址的顺序依次输入(1/0),1代表要修改此处且每个数字间以空格隔开！" << endl;
				for (int j = 0; j < 5; j++)
				{
					cin >> CorArry[j];
				}
				for (int k = 0; k < 5; k++)
				{
					if ((CorArry[k] == 1) && (k == 0))
					{
						cout << "请输入修改后的姓名:" << endl;
						cin >> name;
						p->Parry[i].name = name;
					}
					else if ((CorArry[k] == 1) && (k == 1))
					{
						cout << "请输入修改后的性别:" << endl;
						while (true)
						{
							cin >> sex;
							if (sex == "男" || sex == "女")
							{
								p->Parry[i].sex = sex;
								break;
							}
							else {
								cout << "输入有误请重新输入!" << endl;
							}
						}
					}
					else if ((CorArry[k] == 1) && (k == 2))
					{
						cout << "请输入修改后的年龄:" << endl;
						while (true)
						{
							cin >> age;
							if (age > 0 && age < 120)
							{
								p->Parry[i].age = age;
								break;
							}
							else
							{
								cout << "输入有误请重新输入！" << endl;
							}
							
						}
					}
					else if ((CorArry[k] == 1) && (k == 3))
					{
						cout << "请输入修改后的联系方式:" << endl;
						while (true)
						{
							cin >> phone;
							if (int(log10(phone) + 1) == 11)
							{
								p->Parry[i].phone = phone;
								break;
							}	
							else
							{
								cout << "输入有误请重新输入！" << endl;
							}
						}
					}
					else if ((CorArry[k] == 1) && (k == 4))
					{
						cout << "请输入修改后的家庭住址:" << endl;
						cin >> address;
						p->Parry[i].address = address;
					}
				}
				cout << "修改成功！" << endl;
			}
			else
			{
				cout << "不存在该联系人！" << endl;
				break;
			}
		}
	}
	//请按任意键继续
	system("pause");
	//清屏操作
	system("cls");
}


//查找联系人功能
void FindPerson(Addressbook *p)
{
	string name;
	int flag = 0;
	int flag1 = 0;
	if (p->size == 0)
	{ 
		flag1 = 1;
		cout << "通讯录为空！" << endl;
	}
	else
	{
		cout << "请输入要查找的联系人的姓名:" << endl;
		cin >> name;
		for (int i = 0; i < p->size; i++)
		{
			if (p->Parry[i].name == name)
			{
				flag = 1;
				cout << "姓名:" << p->Parry[i].name << "\t";
				cout << "性别:" << p->Parry[i].sex << "\t";
				cout << "年龄:" << p->Parry[i].age << "\t";
				cout << "联系方式:" << p->Parry[i].phone << "\t";
				cout << "家庭住址:" << p->Parry[i].address << endl;
			}
		}
	}
	if (flag == 0 && flag1 == 0)
	{
		cout << "不存在该联系人！" << endl;
	}

	//请按任意键继续
	system("pause");
	//清屏操作
	system("cls");
}

//显示联系人功能
void  showPerson(Addressbook *p)
{
	if (p->size == 0)
	{
		cout << "联系人为空!!" << endl;
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << "姓名:" << p->Parry[i].name << "\t";
			cout << "性别:" << p->Parry[i].sex << "\t";
			cout << "年龄:" << p->Parry[i].age << "\t";
			cout << "联系方式:" << p->Parry[i].phone << "\t";
			cout << "家庭住址:" << p->Parry[i].address << endl;
		}
	}
	//请按任意键继续
	system("pause");
	//清屏操作
	system("cls");
}


void CleanPerson(Addressbook *p)
{
	//将size置为零即可。
	int num = 0;
	cout << "确定清空请按-->1" << endl;
	cin >> num;
	if (num == 1)
	{
		p->size = 0;
		cout << "联系人已经清空！" << endl;
	}
	//请按任意键继续
	system("pause");
	//清屏操作
	system("cls");
}

int main()
{
	Addressbook p;
	p.size = 0;

	while (true)
	{
		menu();
		cout << "请输入要进行通讯录操作前的序号:";
		int Chosenum;
		cin >> Chosenum;
		switch (Chosenum)
		{
		case 1:
			Add(&p);//利用地址传递修饰实参
			break;
		case 2:
			deletPerson(&p);
			break;
		case 3:
			CorrectPerson(&p);
			break;
		case 4:
			FindPerson(&p);
			break;
		case 5:
			showPerson(&p);
			break;
		case 6:
			CleanPerson(&p);
			break;
		case 0:
			cout << "系统提示:通讯录系统已退出，欢迎继续使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}