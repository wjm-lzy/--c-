#include"order.h"

Order::Order() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuid;
	string stuname;
	string roomid;
	string status;

	this->m_size = 0;

	while (ifs >> date && ifs >> interval && ifs >> stuid && ifs >> stuname && ifs >> roomid && ifs >> status) {
		string key;
		string value;
		map<string, string> m;

		int pos = date.find(":");
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos);
			m.insert(make_pair(key, value));
		}
		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos);
			m.insert(make_pair(key, value));
		}
		pos = stuid.find(":");
		if (pos != -1) {
			key = stuid.substr(0, pos);
			value = stuid.substr(pos + 1, stuid.size() - pos);
			m.insert(make_pair(key, value));
		}
		pos = stuname.find(":");
		if (pos != -1) {
			key = stuname.substr(0, pos);
			value = stuname.substr(pos + 1, stuname.size() - pos);
			m.insert(make_pair(key, value));
		}
		pos = roomid.find(":");
		if (pos != -1) {
			key = roomid.substr(0, pos);
			value = roomid.substr(pos + 1, roomid.size() - pos);
			m.insert(make_pair(key, value));
		}
		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos);
			m.insert(make_pair(key, value));
		}
		this->m_orderdata.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
}
void Order::updateorder() {
	if (this->m_size == 0)
		return;
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0;i < m_size;i++) {
		ofs << "date:" << this->m_orderdata[i]["date"] << " ";
		ofs << "interval:" << this->m_orderdata[i]["interval"] << " ";
		ofs << "stuid:" << this->m_orderdata[i]["stuid"] << " ";
		ofs << "stuname:" << this->m_orderdata[i]["stuname"] << " ";
		ofs << "roomid:" << this->m_orderdata[i]["roomid"] << " ";
		ofs << "status:" << this->m_orderdata[i]["status"] << " ";
	}
	ofs.close();
}

