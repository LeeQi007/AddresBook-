#include"boss.h"
Boss::Boss(int id, string name, int did)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_departID = did;
}
void Boss::showInfo()
{
	cout << "职工编号:" << this->m_ID
		<< "\t职工姓名:" << this->m_name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:总负责人" << endl;
}
string Boss::getDeptName()
{
	return string("老板");
}