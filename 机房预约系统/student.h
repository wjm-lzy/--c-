#pragma once
# include"identity.h"
#include"room.h"
#include<fstream>
#include<vector>
#include"global.h"
using namespace std;

class Student :public Identity {
public:
	Student();
	Student(int id, string name, string pwd);
	virtual void openmenu();
	void applyorder();
	void showmyorder();
	void cancelorder();
	int m_id;
	vector<room> vroom;
};