#pragma once
#include<iostream>
#include<map>
#include"global.h"
#include<fstream>
using namespace std;
class Order {
public:
	Order();
	void updateorder();
	map<int, map<string, string>> m_orderdata;
	int m_size;
};