#include"workManager.h"


workManager::workManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在！" << endl;
		this->m_Num = 0;
		this->m_NumArr = NULL;
		this->m_FilseIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在但是数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空！" << endl;
		this->m_Num = 0;
		this->m_NumArr = NULL;
		this->m_FilseIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在并存在数据
	int num = this->getm_Num();
	//cout << "职工人数为:" << num << endl;
	this->m_Num = num;
	//开辟空间
	this->m_NumArr = new Worker*[this->m_Num];
	//将文件的数据，存到数组中
	this->initEmp();
	//测试代码
	/*for (int i = 0; i < this->m_Num; i++)
	{
		cout << "职工编号:" << this->m_NumArr[i]->m_ID<<" "
			<< "姓名:" << this->m_NumArr[i]->m_name<<" "
			<< "部门编号:" << this->m_NumArr[i]->m_departID << endl;
	}*/
}

void workManager::SaveFile()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_Num; i++)
	{
		ofs << this->m_NumArr[i]->m_ID << " "
			<< this->m_NumArr[i]->m_name << " "
			<< this->m_NumArr[i]->m_departID << endl;
	}
	ofs.close();
}

int workManager::getm_Num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}


void workManager::showMeau()
{
	cout << "****************************" << endl;
	cout << "********职工管理系统********" << endl;
	cout << "******* 0.退出管理程序 *****" << endl;
	cout << "******* 1.增加职工信息 *****" << endl;
	cout << "******* 2.显示职工信息 *****" << endl;
	cout << "******* 3.删除职工信息 *****" << endl;
	cout << "******* 4.修改职工信息 *****" << endl;
	cout << "******* 5.查找职工信息 *****" << endl;
	cout << "******* 6.按照编号排序 *****" << endl;
	cout << "******* 7.清空所有文档 *****" << endl;
	cout << "****************************" << endl;
	cout << endl;
}

void workManager::Exit()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

void workManager::Add()
{
	cout << "添加的职工数量:" << endl;
	int add = 0;
	cin >> add;

	if (add > 0)
	{
		int newsize = this->m_Num + add;//新空间人数=原来的人数+新增的人数
		Worker** newspace = new Worker*[newsize];
		if (this->m_NumArr != NULL)
		{
			for (int i = 0; i < this->m_Num; i++)
			{
				newspace[i] = this->m_NumArr[i];
			}
		}
		for (int i = 0; i < add; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个职工的编号" << endl;
			cin >> id;
			
			cout << "请输入第" << i + 1 << "个职工的姓名" << endl;
			cin >> name;

			cout << "请选择该职工的岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker * worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的职工指针保存到数组
			newspace[this->m_Num + i] = worker;
		}
		//释放原有的空间
		delete[] this->m_NumArr;
		this->m_NumArr = newspace;
		this->m_Num = newsize;
		//更新文件不为空
		this->m_FilseIsEmpty = false;
		cout << "成功添加" << add << "名新职工" << endl;
		//保存到文件中
		this->SaveFile();
	}
	else
	{
		cout << "数据有误！" << endl;
	}
	system("pause");
	system("cls");
}



void workManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker *worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else
		{
			worker = new Boss(id, name, did);
		}
		this->m_NumArr[index] = worker;
		index++;
	}
	ifs.close();
}



void workManager::showPerosn()
{
	if (this->m_FilseIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_Num; i++)
		{
			this->m_NumArr[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int workManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_Num; i++)
	{
		if (this->m_NumArr[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void workManager::deletePerson()
{
	if (this->m_FilseIsEmpty)
	{
		cout << "文件不存在或者为空！" << endl;
	}
	else
	{
		int id;
		cout << "请输入要删除的职工编号" << endl;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "职工不存在,删除失败！" << endl;
		}
		else
		{
			for (int i = index; i < this->m_Num - 1; i++)
			{
				this->m_NumArr[i] = this->m_NumArr[i + 1];
			}
			this->m_Num--;
			this->SaveFile();
			cout << "删除成功！" << endl;
		}
	}
	system("pause");
	system("cls");
}


void workManager::Correct()
{
	if (this->m_FilseIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入要修改的职工编号:" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_NumArr[ret];
			int newId = 0;
			string name = "";
			int did = 0;
			cout << "查找到了" << ret + 1 << "号员工，请输入新的职工号" << endl;
			cin >> newId;
			cout << "请输入姓名:" << endl;
			cin >> name;
			cout << "请选择该职工的岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> did;

			Worker *w = NULL;
			switch (did)
			{
			case 1:
				w = new Employee(newId, name, did);
				break;
			case 2:
				w = new Manager(newId, name, did);
				break;
			case 3:
				w = new Boss(newId, name, did);
				break;
			default:
				break;
			}
			this->m_NumArr[ret] = w;
			cout << "修改成功！" << endl;
			this->SaveFile();
		}
		else
		{
			cout << "修改失败，未找到该职工！" << endl;
		}
	}
	system("pause");
	system("cls");
}




void workManager::FindPerson()
{
	if (this->m_FilseIsEmpty)
	{
		cout << "文件不存在或者为空！" << endl;
	}
	else
	{
		cout << "请输入查找方式" << endl;
		cout << "1.按照职工编号查找" << endl;
		cout << "2.按照职工姓名查找" << endl;

		int id;
		cin >> id;
		if (id == 1)
		{
			int m_id;
			cout << "请输入要查找的职工编号" << endl;
			cin >> m_id;
			int ret = IsExist(m_id);
			if (ret != -1)
			{
				cout << "查找成功，其资料信息为:" << endl;
				this->m_NumArr[ret]->showInfo();
			}
		}
		else if (id == 2)
		{
			string name;
			cout << "请输入要查找的职工姓名" << endl;
			cin >> name;

			//加入判断是否查到的标志
			bool flag = false;
			for (int i = 0; i < m_Num; i++)
			{
				if (this->m_NumArr[i]->m_name == name)
				{
					cout << "查找成功！" << endl;
					cout << "资料信息如下：" << endl;

					flag = true;
					this->m_NumArr[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败！" << endl;
			}
		}
		else
		{
			cout << "查找失败，不存在该员工！" << endl;
		}
	}
	system("pause");
	system("cls");
}



void workManager::IdSort()
{
	if (this->m_FilseIsEmpty)
	{
		cout << "文件不存在或者为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入想要排序的序号" << endl;
		cout << "1.升序排序" << endl;
		cout << "2.降序排序" << endl;
		int num;
		cin >> num;
		for (int i = 0; i < m_Num; i++)
		{
			int temp = i;
			for (int j = i+1; j < m_Num; j++)
			{
				if (num == 1)
				{
					if (this->m_NumArr[temp]->m_ID > this->m_NumArr[j]->m_ID)
					{
						temp = j;
					}
				}
				else
				{
					if (this->m_NumArr[temp]->m_ID < this->m_NumArr[j]->m_ID)
					{
						temp = j;
					}
				}
			}
			if (i != temp)
			{
				Worker *w = this->m_NumArr[i];
				this->m_NumArr[i] = this->m_NumArr[temp];
				this->m_NumArr[temp] = w;
			}
		}
		cout << "排序成功，排序结果为：" << endl;
		this->SaveFile();
		this->showPerosn();
	}
}

void workManager::clean()
{
	cout << "是否确认清空文件？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//删除文件后重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_NumArr != NULL)
		{
			for (int i = 0; i < m_Num; i++)
			{
				delete this->m_NumArr[i];
				this->m_NumArr[i] = NULL;
			}
			delete[]this->m_NumArr;
			this->m_NumArr = NULL;
			this->m_Num = 0;
			this->m_FilseIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}


workManager::~workManager()
{
	if (this->m_NumArr != NULL)
	{
		delete[] this->m_NumArr;
		this->m_NumArr = NULL;
	}
}