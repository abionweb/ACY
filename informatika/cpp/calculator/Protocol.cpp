#include "Protocol.h"

Protocol::Protocol() {
}

Protocol::~Protocol() {
}

void Protocol::addRecord(char mod_attr, float old_v, std::string new_v) {
	modified_attr = old_v;
	std::ostringstream ss;
	ss << old_v;
	old_value = ss.str();
}
