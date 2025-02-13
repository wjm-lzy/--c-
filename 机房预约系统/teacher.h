#pragma once
# include"identity.h"
using namespace std;
class Teacher :public Identity {
public:
	Teacher();
	Teacher(int empId, string name, string pwd);
	virtual void openmenu();
	void showallorder();
	void validorder();
	int m_empid;
};