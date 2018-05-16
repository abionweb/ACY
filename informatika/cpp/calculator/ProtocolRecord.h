#ifndef PROTOCOLRECORD_H_
#define PROTOCOLRECORD_H_
#include <string>
#include <fstream>

class ProtocolRecord {
public:
	char mod_attr;
	std::string old_value, new_value;

	ProtocolRecord() {};
	ProtocolRecord(char mod_at, std::string old_v, std::string new_v);
	virtual ~ProtocolRecord() {};

	friend std::fstream& operator >> (std::fstream& fin, ProtocolRecord& r);
	friend std::fstream& operator << (std::fstream& fout, const ProtocolRecord& r);
	friend std::ostream& operator << (std::ostream &out, const ProtocolRecord& r);
};

#endif /* PROTOCOLRECORD_H_ */
