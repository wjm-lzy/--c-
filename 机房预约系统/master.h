#pragma once
#include"identity.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"room.h"
using namespace std;
class Master :public Identity {
public:
	Master();
	Master(string name,string pwd);
	virtual void openmenu();
	void addperson();
	void showperson();
	void showcomputer();
	void clearfile();
	void initvector();
	void initvector_1();
	vector<Student> vstu;
	vector<Teacher> vtea;
	vector<room> vroom;
};