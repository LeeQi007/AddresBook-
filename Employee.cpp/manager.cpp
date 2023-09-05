#include"manager.h"
Manager::Manager(int id, string name, int did)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_departID = did;
}
void Manager::showInfo()
{
	cout << "职工编号:" << this->m_ID
		<< "\t职工姓名:" << this->m_name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:完成老板交给任务以及派发员工任务" << endl;
}
string Manager::getDeptName()
{
	return string("经理");
}