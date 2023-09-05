#include"employee.h"
Employee::Employee(int id, string name, int did)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_departID = did;
}
void Employee::showInfo()
{
	cout << "职工编号:" << this->m_ID
		<< "\t职工姓名:" << this->m_name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:完成任务" << endl;
}
string Employee::getDeptName()
{
	return string("员工");
}