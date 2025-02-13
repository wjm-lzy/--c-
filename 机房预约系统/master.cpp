#include"master.h"
#include"global.h"
#include<fstream>
#include<algorithm>
using namespace std;

Master::Master() {

}
Master::Master(string name, string pwd) {
	this->M_name = name;
	this->M_pwd = pwd;
	this->initvector_1();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	room c;
	while (ifs >> c.m_roomid && ifs >> c.m_maxnum) {
		vroom.push_back(c);
	}
	cout << "当前机房数目为：" << vroom.size() << endl;
	ifs.close();
}
void Master::openmenu() {
	this->initvector();
	cout << "\t\t|欢迎使用管理员系统\n" << endl;
	cout << "\t\t|------------|\n";
	cout << "\t\t|1.添加账号  |\n";
	cout << "\t\t|2.查看账号  |\n";
	cout << "\t\t|3.查看机房  |\n";
	cout << "\t\t|4.清空预约  |\n";
	cout << "\t\t|0.exit      |\n";
	cout << "\t\t|------------|\n";
	cout << "\t\t|请输入您的选择:";

}
void Master::addperson() {
	system("cls");
	cout << "请输入要添加的账号类型" << endl;
	cout << "1.添加老师" << endl;
	cout << "2.添加学生" << endl;
	cout << "0.退出" << endl;
	string filename;
	string tip;
	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1) {
		filename = TEACHER_FILE;
		tip = "请输入职工号：";
	}
	else if(select == 2){
		filename = STUDENT_FILE;
		tip = "请输入学号";
	}
	else {
		system("cls");
		return;
	}
	ofs.open(filename, ios::out | ios::app);
	string name;
	int id;
	string pwd;
	cout << tip << endl;
	cin >> id;
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " <<pwd<<" "<< endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
	ofs.close();
}
void show_student(Student &s) {
	cout << "学号：" << s.m_id <<" | " << "姓名：" << s.M_name << " | " <<"密码:" << s.M_pwd << endl;
}
void show_teacher(Teacher& s) {
	cout << "职工号：" << s.m_empid << " | " << "姓名：" << s.M_name << " | " << "密码:"  <<s.M_pwd << endl;
}
void Master::showperson() {
	system("cls");
	cout << "请输入查看内容：" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		system("cls");
		cout << "所有学生信息如下：" << endl;
		for_each(vstu.begin(), vstu.end(), show_student);
	}
	else if(select == 2) {
		system("cls");
		cout << "所有老师信息如下：" << endl;
		for_each(vtea.begin(), vtea.end(), show_teacher);
	}
	system("pause");
	system("cls");
}
void Master::showcomputer() {
	system("cls");
	cout << "机房信息如下：" << endl;
	for (vector<room>::iterator it = vroom.begin();it != vroom.end();it++) {
		cout << "机房编号：" << it->m_roomid << " | " << "机房最大容量：" << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}
void Master::clearfile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

void Master::initvector() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	vstu.clear();
	vtea.clear();

	Student s;
	while (ifs >> s.m_id && ifs >> s.M_name && ifs >> s.M_pwd) {
		vstu.push_back(s);
	}
	cout << "当前学生数量为:" << vstu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_empid && ifs >> t.M_name && ifs >> t.M_pwd) {
		vtea.push_back(t);
	}
	cout << "当前老师数量为:" << vtea.size() << endl;
	ifs.close();
}

void Master::initvector_1() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	vstu.clear();
	vtea.clear();

	Student s;
	while (ifs >> s.m_id && ifs >> s.M_name && ifs >> s.M_pwd) {
		vstu.push_back(s);
	}
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_empid && ifs >> t.M_name && ifs >> t.M_pwd) {
		vtea.push_back(t);
	}
	ifs.close();
}