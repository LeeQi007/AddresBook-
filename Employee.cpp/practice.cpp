#include"workManager.h"


workManager::workManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ������ڣ�" << endl;
		this->m_Num = 0;
		this->m_NumArr = NULL;
		this->m_FilseIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڵ�������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" << endl;
		this->m_Num = 0;
		this->m_NumArr = NULL;
		this->m_FilseIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڲ���������
	int num = this->getm_Num();
	//cout << "ְ������Ϊ:" << num << endl;
	this->m_Num = num;
	//���ٿռ�
	this->m_NumArr = new Worker*[this->m_Num];
	//���ļ������ݣ��浽������
	this->initEmp();
	//���Դ���
	/*for (int i = 0; i < this->m_Num; i++)
	{
		cout << "ְ�����:" << this->m_NumArr[i]->m_ID<<" "
			<< "����:" << this->m_NumArr[i]->m_name<<" "
			<< "���ű��:" << this->m_NumArr[i]->m_departID << endl;
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
	cout << "********ְ������ϵͳ********" << endl;
	cout << "******* 0.�˳�������� *****" << endl;
	cout << "******* 1.����ְ����Ϣ *****" << endl;
	cout << "******* 2.��ʾְ����Ϣ *****" << endl;
	cout << "******* 3.ɾ��ְ����Ϣ *****" << endl;
	cout << "******* 4.�޸�ְ����Ϣ *****" << endl;
	cout << "******* 5.����ְ����Ϣ *****" << endl;
	cout << "******* 6.���ձ������ *****" << endl;
	cout << "******* 7.��������ĵ� *****" << endl;
	cout << "****************************" << endl;
	cout << endl;
}

void workManager::Exit()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void workManager::Add()
{
	cout << "��ӵ�ְ������:" << endl;
	int add = 0;
	cin >> add;

	if (add > 0)
	{
		int newsize = this->m_Num + add;//�¿ռ�����=ԭ��������+����������
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
			cout << "�������" << i + 1 << "��ְ���ı��" << endl;
			cin >> id;
			
			cout << "�������" << i + 1 << "��ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//��������ְ��ָ�뱣�浽����
			newspace[this->m_Num + i] = worker;
		}
		//�ͷ�ԭ�еĿռ�
		delete[] this->m_NumArr;
		this->m_NumArr = newspace;
		this->m_Num = newsize;
		//�����ļ���Ϊ��
		this->m_FilseIsEmpty = false;
		cout << "�ɹ����" << add << "����ְ��" << endl;
		//���浽�ļ���
		this->SaveFile();
	}
	else
	{
		cout << "��������" << endl;
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
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
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
		cout << "�ļ������ڻ���Ϊ�գ�" << endl;
	}
	else
	{
		int id;
		cout << "������Ҫɾ����ְ�����" << endl;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "ְ��������,ɾ��ʧ�ܣ�" << endl;
		}
		else
		{
			for (int i = index; i < this->m_Num - 1; i++)
			{
				this->m_NumArr[i] = this->m_NumArr[i + 1];
			}
			this->m_Num--;
			this->SaveFile();
			cout << "ɾ���ɹ���" << endl;
		}
	}
	system("pause");
	system("cls");
}


void workManager::Correct()
{
	if (this->m_FilseIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ�����:" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_NumArr[ret];
			int newId = 0;
			string name = "";
			int did = 0;
			cout << "���ҵ���" << ret + 1 << "��Ա�����������µ�ְ����" << endl;
			cin >> newId;
			cout << "����������:" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			cout << "�޸ĳɹ���" << endl;
			this->SaveFile();
		}
		else
		{
			cout << "�޸�ʧ�ܣ�δ�ҵ���ְ����" << endl;
		}
	}
	system("pause");
	system("cls");
}




void workManager::FindPerson()
{
	if (this->m_FilseIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ" << endl;
		cout << "1.����ְ����Ų���" << endl;
		cout << "2.����ְ����������" << endl;

		int id;
		cin >> id;
		if (id == 1)
		{
			int m_id;
			cout << "������Ҫ���ҵ�ְ�����" << endl;
			cin >> m_id;
			int ret = IsExist(m_id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����������ϢΪ:" << endl;
				this->m_NumArr[ret]->showInfo();
			}
		}
		else if (id == 2)
		{
			string name;
			cout << "������Ҫ���ҵ�ְ������" << endl;
			cin >> name;

			//�����ж��Ƿ�鵽�ı�־
			bool flag = false;
			for (int i = 0; i < m_Num; i++)
			{
				if (this->m_NumArr[i]->m_name == name)
				{
					cout << "���ҳɹ���" << endl;
					cout << "������Ϣ���£�" << endl;

					flag = true;
					this->m_NumArr[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ�" << endl;
			}
		}
		else
		{
			cout << "����ʧ�ܣ������ڸ�Ա����" << endl;
		}
	}
	system("pause");
	system("cls");
}



void workManager::IdSort()
{
	if (this->m_FilseIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������Ҫ��������" << endl;
		cout << "1.��������" << endl;
		cout << "2.��������" << endl;
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
		cout << "����ɹ���������Ϊ��" << endl;
		this->SaveFile();
		this->showPerosn();
	}
}

void workManager::clean()
{
	cout << "�Ƿ�ȷ������ļ���" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//ɾ���ļ������´���
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
		cout << "��ճɹ���" << endl;
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