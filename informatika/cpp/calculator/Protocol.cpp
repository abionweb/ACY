#include "Protocol.h"

Protocol::Protocol() {
}

Protocol::~Protocol() {
}

void Protocol::addRecord(char mod_attr, float old_v, std::string new_v) {
	modified_attr = mod_attr;
	std::ostringstream ss;
	ss << old_v;
	old_value = ss.str();
}


void Protocol::addRecord(char mod_attr, std::string old_v, std::string new_v) {
	modified_attr = mod_attr;
	old_value = old_v;
}

void Protocol::addRecord(char mod_attr, float old_v, float new_v) {
	modified_attr = mod_attr;
	std::ostringstream ss1, ss2;
	ss1 << old_v;
	ss2 << new_v;
	old_value = ss1.str();
}
