#include"student.h"
#include"order.h"
#include<typeinfo>
#include<stdlib.h>
#include<string.h>


Student::Student() {

}
Student::Student(int id, string name, string pwd) {
	this->m_id = id;
	this->M_name = name;
	this->M_pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	room c;
	while (ifs >> c.m_roomid && ifs >> c.m_maxnum) {
		vroom.push_back(c);
	}
	cout << "��ǰ������ĿΪ��" << vroom.size() << endl;
	ifs.close();
}
void Student::openmenu() {
	cout << "\t\t|��ӭʹ��ѧ��ϵͳ\n" << endl;
	cout << "\t\t|----------------|\n";
	cout << "\t\t|1.����ԤԼ      |\n";
	cout << "\t\t|2.�鿴�ҵ�ԤԼ  |\n";
	cout << "\t\t|3.ȡ��ԤԼ      |\n";
	cout << "\t\t|0.exit          |\n";
	cout << "\t\t|----------------|\n";
	cout << "\t\t|����������ѡ��:";
}
void Student::applyorder() {
	cout << "����������ԤԼʱ��" << endl;
	cout << "1.��1" << endl;
	cout << "2.��2" << endl;
	cout << "3.��3" << endl;
	cout << "4.��4" << endl;
	cout << "5.��5" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "������ԤԼʱ���" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "������ԤԼ����" << endl;
	cout << "1.����1" << endl;
	cout << "2.����2" << endl;
	cout << "3.����3" << endl;

	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ�,�������" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuid:" << this->m_id << " ";
	ofs << "stuname:" << this->M_name << " ";
	ofs << "roomid:" << room << " ";
	ofs << "status:" << 1 << " ";
	ofs.close();
	system("pause");
	system("cls");

}
void Student::showmyorder() {
	Order of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < of.m_size;i++) {
		
		if (atoi(of.m_orderdata[i]["stuid"].c_str()) == this->m_id) {
			cout << "ԤԼ���ڣ���" << of.m_orderdata[i]["date"]<<" | ";
			cout << "ʱ��" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����")<< " | ";
			cout << "����" << of.m_orderdata[i]["roomid"] << " ";
			string status = "״̬��";
			if (of.m_orderdata[i]["status"] == "1") status += "�����";
			else if (of.m_orderdata[i]["status"] == "2") status += "ԤԼ�ɹ�";
			else if (of.m_orderdata[i]["status"] == "-1") status += "ԤԼʧ��";
			else
				status = "ԤԼȡ��";
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
	return;
}
void Student::cancelorder() {
	Order of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "������ȡ���ļ�¼" << endl;
	vector<int> v;
	int index = 1;
	for (int i = 0;i < of.m_size;i++) {
		if (atoi(of.m_orderdata[i]["stuid"].c_str()) == this->m_id) {
			if (of.m_orderdata[i]["status"] == "1" || of.m_orderdata[i]["status"] == "2") {
				v.push_back(i);
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ���" << of.m_orderdata[i]["date"] << " | ";
				cout << "ʱ��" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����") << " | ";
				cout << "����" << of.m_orderdata[i]["roomid"] << " ";
				string status = "״̬��";
				if (of.m_orderdata[i]["status"] == "1") status += "�����";
				else if (of.m_orderdata[i]["status"] == "2") status += "ԤԼ�ɹ�";
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) break;
			else {
				of.m_orderdata[v[select - 1]]["status"] = "0";
				of.updateorder();
				cout << "�Ѿ�ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
	return;
}
int m_id;