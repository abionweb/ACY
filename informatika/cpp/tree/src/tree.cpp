#include "Dialog.h"
#include <algorithm>
#include <Vector>
using namespace std;

int main() {
	Dialog d;
	int count;
	std::vector<int> v;
	int E;
	count = d.enterCount();
	if (d.enterManually()) {
		for (int i = 0; i < count; i++) {
			E = d.enterElement();
			v.push_back(E);
		}
	} else {
		for(int i = 0; i < count; i++) {
			E = (rand()%1000);
			v.push_back(E);
		}
	}
	sort (v.begin(), v.end());
	for(int i = 0; i < count; i++) cout << v[i] << "\t";
		cout << endl;
	return 0;
}
