#ifndef PROTOCOL_H_
#define PROTOCOL_H_
#include <string>
#include <sstream>
class Protocol {
public:
	Protocol();
	virtual ~Protocol();

	void addRecord(char mod_attr, std::string old_v, std::string new_v);
	void addRecord(char mod_attr, float old_v, std::string new_v);
	void addRecord(char mod_attr, float old_v, float new_v);
	void undoLastEntry();
private:
	char modified_attr;
	std::string old_value;
};

#endif /* PROTOCOL_H_ */
