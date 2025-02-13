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
	cout << "\t\t|欢迎使用教师系统\n" << endl;
	cout << "\t\t|----------------|\n";
	cout << "\t\t|1.查看所有预约  |\n";
	cout << "\t\t|2.审核预约      |\n";
	cout << "\t\t|0.exit          |\n";
	cout << "\t\t|----------------|\n";
	cout << "\t\t|请输入您的选择:";
}
void Teacher::showallorder() {
	Order of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < of.m_size;i++) {
		cout << i+1<< "、";
		cout << "预约日期：周" << of.m_orderdata[i]["date"] << " | ";
		cout << "时段" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午") << " | ";
		cout << " |学号：" << of.m_orderdata[i]["stuid"];
		cout << " |姓名" << of.m_orderdata[i]["stuname"];
		cout << " |机房" << of.m_orderdata[i]["roomid"] << " ";
		string status = "状态：";
		if (of.m_orderdata[i]["status"] == "1") status += "审核中";
		else if (of.m_orderdata[i]["status"] == "2") status += "预约成功";
		else if (of.m_orderdata[i]["status"] == "-1") status += "预约失败";
		else status = "预约已经取消";
		cout << status << endl;
	}
	system("pause");
	system("cls");
	
}
void Teacher::validorder() {
	Order of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下" << endl;
	vector<int> v;
	int index = 0;
	for (int i = 0;i < of.m_size;i++) {
		if (of.m_orderdata[i]["status"] == "1") {
			v.push_back(i);
			cout << ++index << "、";
			cout << "预约日期：周" << of.m_orderdata[i]["date"] << " | ";
			cout << "时段" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午") << " | ";
			cout << " |学号：" << of.m_orderdata[i]["stuid"];
			cout << " |姓名" << of.m_orderdata[i]["stuname"];
			cout << " |机房" << of.m_orderdata[i]["roomid"] << " ";
			string status = "状态：";
			if (of.m_orderdata[i]["status"] == "1") status += "审核中";
			cout << status << endl;
		}
	}
	cout << "请输入审核的预约记录" << endl;
	int select = 0;
	int ret = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) break;
			else {
				cout << "请输入审核结果" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				cin >> ret;
				if(ret == 1){
					of.m_orderdata[v[select - 1]]["status"] = "2";
				}
				else
					of.m_orderdata[v[select - 1]]["status"] = "-1";
				
				of.updateorder();
				cout << "审核完毕" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
	return;
}