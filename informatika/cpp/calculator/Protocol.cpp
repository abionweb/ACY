#include "Protocol.h"

void Protocol::addRecord(char mod_attr, float old_v, std::string new_v) {
	std::ostringstream ss;
	ss << old_v;
	ProtocolRecord record(mod_attr, ss.str(), new_v);
	addProtocolRecord(record);
}

void Protocol::addRecord(char mod_attr, std::string old_v, std::string new_v) {
	ProtocolRecord record(mod_attr, old_v, new_v);
	addProtocolRecord(record);
}

void Protocol::addRecord(char mod_attr, float old_v, float new_v) {
	std::ostringstream ss1, ss2;
	ss1 << old_v;
	ss2 << new_v;
	ProtocolRecord record(mod_attr, ss1.str(), ss2.str());
	addProtocolRecord(record);
}

void Protocol::addRecord(char mod_attr, char old_v, char new_v) {
	std::string str1(1,old_v), str2(1,new_v);
	ProtocolRecord record(mod_attr, str1, str2);
	addProtocolRecord(record);
}

int Protocol::addProtocolRecord(ProtocolRecord record) {
	std::fstream stream(filename, std::ios::out|std::ios::app);
	if(!stream) {
		return -1;
	}
	stream << record;
	stream.close();
	return 0;
}

std::fstream Protocol::make_file() {
	std::fstream stream(filename, std::ios::out|std::ios::trunc);
	return stream;
}

int Protocol::print_protocol() {
	std::fstream stream(filename, std::ios::in);
	if (!stream) return -1;
	ProtocolRecord record; int i = 0;
	while (stream>>record) {
		std::cout << record << "\n";
	}
	stream.close();
	return i;
}

ProtocolRecord Protocol::get_last_record() {
	ProtocolRecord record;
	std::fstream stream(filename, std::ios::in);
	if (stream) {
		while (stream>>record) {};
		stream.close();
	}
	return record;
}
