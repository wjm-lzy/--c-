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
	cout << "当前机房数目为：" << vroom.size() << endl;
	ifs.close();
}
void Student::openmenu() {
	cout << "\t\t|欢迎使用学生系统\n" << endl;
	cout << "\t\t|----------------|\n";
	cout << "\t\t|1.申请预约      |\n";
	cout << "\t\t|2.查看我的预约  |\n";
	cout << "\t\t|3.取消预约      |\n";
	cout << "\t\t|0.exit          |\n";
	cout << "\t\t|----------------|\n";
	cout << "\t\t|请输入您的选择:";
}
void Student::applyorder() {
	cout << "请输入申请预约时间" << endl;
	cout << "1.周1" << endl;
	cout << "2.周2" << endl;
	cout << "3.周3" << endl;
	cout << "4.周4" << endl;
	cout << "5.周5" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "请输入预约时间段" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请输入预约机房" << endl;
	cout << "1.机房1" << endl;
	cout << "2.机房2" << endl;
	cout << "3.机房3" << endl;

	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功,正在审核" << endl;

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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < of.m_size;i++) {
		
		if (atoi(of.m_orderdata[i]["stuid"].c_str()) == this->m_id) {
			cout << "预约日期：周" << of.m_orderdata[i]["date"]<<" | ";
			cout << "时段" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午")<< " | ";
			cout << "机房" << of.m_orderdata[i]["roomid"] << " ";
			string status = "状态：";
			if (of.m_orderdata[i]["status"] == "1") status += "审核中";
			else if (of.m_orderdata[i]["status"] == "2") status += "预约成功";
			else if (of.m_orderdata[i]["status"] == "-1") status += "预约失败";
			else
				status = "预约取消";
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入取消的记录" << endl;
	vector<int> v;
	int index = 1;
	for (int i = 0;i < of.m_size;i++) {
		if (atoi(of.m_orderdata[i]["stuid"].c_str()) == this->m_id) {
			if (of.m_orderdata[i]["status"] == "1" || of.m_orderdata[i]["status"] == "2") {
				v.push_back(i);
				cout << index++ << "、 ";
				cout << "预约日期：周" << of.m_orderdata[i]["date"] << " | ";
				cout << "时段" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午") << " | ";
				cout << "机房" << of.m_orderdata[i]["roomid"] << " ";
				string status = "状态：";
				if (of.m_orderdata[i]["status"] == "1") status += "审核中";
				else if (of.m_orderdata[i]["status"] == "2") status += "预约成功";
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) break;
			else {
				of.m_orderdata[v[select - 1]]["status"] = "0";
				of.updateorder();
				cout << "已经取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
	return;
}
int m_id;