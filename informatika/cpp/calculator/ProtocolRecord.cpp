#include "ProtocolRecord.h"

ProtocolRecord::ProtocolRecord(char mod_at, std::string old_v, std::string new_v) {
	mod_attr = mod_at;
	old_value = old_v;
	new_value = new_v;
}

std::fstream& operator >> (std::fstream& fin, ProtocolRecord& r) {
	fin >> r.mod_attr;
	fin >> r.old_value;
	fin >> r.new_value;
	return fin;
}

std::fstream& operator << (std::fstream& fout, const ProtocolRecord& r) {
	fout << r.mod_attr << "\t" << r.old_value << "\t" << r.new_value << "\n";
	return fout;
}

std::ostream& operator << (std::ostream &out, const ProtocolRecord& r) {
	std::string attr;
	switch (r.mod_attr) {
	case '1':
		attr = "первый оператор";
		break;
	case '2':
		attr = "второй оператор";
		break;
	case 'a':
		attr = "действие";
		break;
	case 'f':
		attr = "форму вывода";
		break;
	}
	out << "Меняю " << attr << ". Старое значение: " << r.old_value << ". Новое значение: " << r.new_value << ".";
	return out;
}
