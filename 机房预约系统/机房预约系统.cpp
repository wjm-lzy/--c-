#include <iostream>
#include"global.h"
#include"Identity.h"
#include"student.h"
#include"teacher.h"
#include"master.h"

#include<fstream>
#include<string>
using namespace std;


void mastermenu(Identity*& master) {
	while (true) {
		master->openmenu();
		Master* man = (Master*)master;
		int select = 0;
		cin >> select;
		if (select == 1) {
			cout << "添加账号" << endl;
			man->addperson();
		}
		else if (select == 2) {
			cout << "查看账号" << endl;
			man->showperson();
		}
		else if (select == 3) {
			cout << "查看机房" << endl;
			man->showcomputer();
		}
		else if (select == 4) {
			cout << "清空预约" << endl;
			man->clearfile();
		}
		else {
			delete master;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void studentmenu(Identity*& student) {
	while (true) {
		student->openmenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1) {
			stu->applyorder();
		}
		else if (select == 2) {
			stu->showmyorder();
		}
		else if (select == 3) {
			stu->cancelorder();
		}
		else {
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}






void teachermenu(Identity*& teacher) {
	while (true) {
		teacher->openmenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1) {
			tea->showallorder();
		}
		else if (select == 2) {
			tea->validorder();
		}
		else {
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void Loginin(string filename, int type) {
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(filename,ios::in);
	if (!ifs.is_open()) {
		cout <<endl<< "\t\t|文件不存在" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}
	int id = 0;
	string name;
	string pwd;
	int fid;
	string fname;
	string fpwd;
	if (type == 1) {
		cout << "请输入你的学号:" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	if (type == 1) {
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "验证成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentmenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "验证成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teachermenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		while (ifs >> fname && ifs >> fpwd) {
			if (name == fname && pwd == fpwd) {
				cout << "验证成功" << endl;
				system("pause");
				system("cls");
				person = new Master(name, pwd);
				mastermenu(person);
				return;
			}
		}
	}
	cout << "验证失败" << endl;
	system("pause");
	system("cls");
	return;
}








int main() {
	int select;
	while (true) {
		cout << "\t\t|欢迎使用机房管理系统\n" << endl;
		cout << "\t\t|请输入身份\n" << endl;
		cout << "\t\t|----------|\n";
		cout << "\t\t|1.sudent  |\n";
		cout << "\t\t|2.teacher |\n";
		cout << "\t\t|3.master  |\n";
		cout << "\t\t|0.exit    |\n";
		cout << "\t\t|----------|\n";
		cout << "\t\t|请输入您的选择:";
		cin >> select;
		switch (select) {
		case 1: //student
			Loginin(STUDENT_FILE,select);
			break;
		case 2: //teacher
			Loginin(TEACHER_FILE, select);
			break;
		case 3: //master
			Loginin(MASTER_FILE, select);
			break;
		case 0:
			system("cls");
			cout << "\t\t|------------------|" << endl;
			cout << "\t\t|欢迎下一次使用    |" << endl;
			cout << "\t\t|------------------|" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "\t\t|输入有误，请重新输入";
			system("pause");
			system("cls");
			break;
		}

	}
	
	system("pause");

	return 0;
}