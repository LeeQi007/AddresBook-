#include"employee.h"
Employee::Employee(int id, string name, int did)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_departID = did;
}
void Employee::showInfo()
{
	cout << "ְ�����:" << this->m_ID
		<< "\tְ������:" << this->m_name
		<< "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:�������" << endl;
}
string Employee::getDeptName()
{
	return string("Ա��");
}