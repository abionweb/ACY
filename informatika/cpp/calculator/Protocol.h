#ifndef PROTOCOL_H_
#define PROTOCOL_H_
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "ProtocolRecord.h"

class Protocol {
private:
	std::fstream make_file();
	std::string filename = "protocol";
public:
	Protocol() {};
	virtual ~Protocol() {};

	void addRecord(char mod_attr, std::string old_v, std::string new_v);
	void addRecord(char mod_attr, float old_v, std::string new_v);
	void addRecord(char mod_attr, float old_v, float new_v);
	void addRecord(char mod_attr, char old_v, char new_v);
	int addProtocolRecord(ProtocolRecord record);

	ProtocolRecord get_last_record();

	int print_protocol();
};

#endif /* PROTOCOL_H_ */
