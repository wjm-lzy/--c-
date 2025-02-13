#include"teacher.h"
#include"order.h"
#include<vector>

using namespace std;
Teacher::Teacher() {

}
Teacher::Teacher(int empId, string name, string pwd) {
	this->m_empid = empId;
	this->M_name = name;
	this->M_pwd = pwd;
}
void Teacher::openmenu()
{
	cout << "\t\t|��ӭʹ�ý�ʦϵͳ\n" << endl;
	cout << "\t\t|----------------|\n";
	cout << "\t\t|1.�鿴����ԤԼ  |\n";
	cout << "\t\t|2.���ԤԼ      |\n";
	cout << "\t\t|0.exit          |\n";
	cout << "\t\t|----------------|\n";
	cout << "\t\t|����������ѡ��:";
}
void Teacher::showallorder() {
	Order of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < of.m_size;i++) {
		cout << i+1<< "��";
		cout << "ԤԼ���ڣ���" << of.m_orderdata[i]["date"] << " | ";
		cout << "ʱ��" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����") << " | ";
		cout << " |ѧ�ţ�" << of.m_orderdata[i]["stuid"];
		cout << " |����" << of.m_orderdata[i]["stuname"];
		cout << " |����" << of.m_orderdata[i]["roomid"] << " ";
		string status = "״̬��";
		if (of.m_orderdata[i]["status"] == "1") status += "�����";
		else if (of.m_orderdata[i]["status"] == "2") status += "ԤԼ�ɹ�";
		else if (of.m_orderdata[i]["status"] == "-1") status += "ԤԼʧ��";
		else status = "ԤԼ�Ѿ�ȡ��";
		cout << status << endl;
	}
	system("pause");
	system("cls");
	
}
void Teacher::validorder() {
	Order of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼����" << endl;
	vector<int> v;
	int index = 0;
	for (int i = 0;i < of.m_size;i++) {
		if (of.m_orderdata[i]["status"] == "1") {
			v.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ���ڣ���" << of.m_orderdata[i]["date"] << " | ";
			cout << "ʱ��" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����") << " | ";
			cout << " |ѧ�ţ�" << of.m_orderdata[i]["stuid"];
			cout << " |����" << of.m_orderdata[i]["stuname"];
			cout << " |����" << of.m_orderdata[i]["roomid"] << " ";
			string status = "״̬��";
			if (of.m_orderdata[i]["status"] == "1") status += "�����";
			cout << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼" << endl;
	int select = 0;
	int ret = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) break;
			else {
				cout << "��������˽��" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
				cin >> ret;
				if(ret == 1){
					of.m_orderdata[v[select - 1]]["status"] = "2";
				}
				else
					of.m_orderdata[v[select - 1]]["status"] = "-1";
				
				of.updateorder();
				cout << "������" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
	return;
}