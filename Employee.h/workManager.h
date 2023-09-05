#pragma once
#include<iostream>
#include<fstream>
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"
using namespace std;
#define FILENAME "Employee.txt"

class workManager
{
public:
	workManager();
	~workManager();
	void showMeau();
	void Exit();
	void Add();
	int m_Num;
	void SaveFile();
	bool m_FilseIsEmpty;
	int getm_Num();
	void initEmp();
	void showPerosn();
	void deletePerson();
	int IsExist(int id);
	void Correct();
	void FindPerson();
	void IdSort();
	void clean();
	Worker **m_NumArr;
};