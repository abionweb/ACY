#include "Dialog.h"
#include <algorithm>
#include <Vector>
#include <fstream>
#include "Tree.h"

int main() {
	Dialog d;
	std::vector<int> v;
	int count;
	int E;

	switch (d.enterInput()) {
	case 1:
		count = d.enterCount();
		for (int i = 0; i < count; i++) {
			E = d.enterElement();
			v.push_back(E);
		}
		break;
	case 2:
		count = d.enterCount();
		for(int i = 0; i < count; i++) {
			E = (rand()%1000);
			v.push_back(E);
		}
		break;
	case 3:
		std::ifstream stream("Tree.txt");
		if (stream) {
			while (stream >> E) {
				v.push_back(E);
			};
			stream.close();
		}
		count = v.size();
		break;
	}
	sort (v.begin(), v.end());
	cout << "Array of elements generated: " << endl;
	for(int i = 0; i < count; i++) cout << v[i] << "\t";
	cout << endl << endl;

	Tree<int> t(v);
	t.print_tree();

	if (t.find_twin()) {
		cout << endl << "In the tree there are the same elements" << endl;
	} else {
		cout << endl << "In the tree there are no identical elements" << endl;
	}

	cout << endl << "What element will we look for?" << endl;
	E = d.enterElement();
	cout << t.how_many(E) << " items found" << endl;

	int save_status = t.save_to_file("Tree.txt");
	if (save_status) {
		cout << "Writing to the file failed. Error code " << save_status;
	} else {
		cout << "Writing to a file is successful";
	}
	return 0;
}
