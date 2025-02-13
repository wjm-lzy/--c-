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
	cout << "��ǰ������ĿΪ��" << vroom.size() << endl;
	ifs.close();
}
void Master::openmenu() {
	this->initvector();
	cout << "\t\t|��ӭʹ�ù���Աϵͳ\n" << endl;
	cout << "\t\t|------------|\n";
	cout << "\t\t|1.����˺�  |\n";
	cout << "\t\t|2.�鿴�˺�  |\n";
	cout << "\t\t|3.�鿴����  |\n";
	cout << "\t\t|4.���ԤԼ  |\n";
	cout << "\t\t|0.exit      |\n";
	cout << "\t\t|------------|\n";
	cout << "\t\t|����������ѡ��:";

}
void Master::addperson() {
	system("cls");
	cout << "������Ҫ��ӵ��˺�����" << endl;
	cout << "1.�����ʦ" << endl;
	cout << "2.���ѧ��" << endl;
	cout << "0.�˳�" << endl;
	string filename;
	string tip;
	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1) {
		filename = TEACHER_FILE;
		tip = "������ְ���ţ�";
	}
	else if(select == 2){
		filename = STUDENT_FILE;
		tip = "������ѧ��";
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
	cout << "����������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " <<pwd<<" "<< endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();
}
void show_student(Student &s) {
	cout << "ѧ�ţ�" << s.m_id <<" | " << "������" << s.M_name << " | " <<"����:" << s.M_pwd << endl;
}
void show_teacher(Teacher& s) {
	cout << "ְ���ţ�" << s.m_empid << " | " << "������" << s.M_name << " | " << "����:"  <<s.M_pwd << endl;
}
void Master::showperson() {
	system("cls");
	cout << "������鿴���ݣ�" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		system("cls");
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vstu.begin(), vstu.end(), show_student);
	}
	else if(select == 2) {
		system("cls");
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vtea.begin(), vtea.end(), show_teacher);
	}
	system("pause");
	system("cls");
}
void Master::showcomputer() {
	system("cls");
	cout << "������Ϣ���£�" << endl;
	for (vector<room>::iterator it = vroom.begin();it != vroom.end();it++) {
		cout << "������ţ�" << it->m_roomid << " | " << "�������������" << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}
void Master::clearfile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}

void Master::initvector() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	vstu.clear();
	vtea.clear();

	Student s;
	while (ifs >> s.m_id && ifs >> s.M_name && ifs >> s.M_pwd) {
		vstu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ:" << vstu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_empid && ifs >> t.M_name && ifs >> t.M_pwd) {
		vtea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ:" << vtea.size() << endl;
	ifs.close();
}

void Master::initvector_1() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
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
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_empid && ifs >> t.M_name && ifs >> t.M_pwd) {
		vtea.push_back(t);
	}
	ifs.close();
}