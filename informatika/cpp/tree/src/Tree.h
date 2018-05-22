#ifndef TREE_H_
#define TREE_H_
#include <iostream>
#include <fstream>
#include <Vector>


template <class T>
class Tree {
public:
	T key;
	int count;
	Tree<T>* left = 0;
	Tree<T>* right = 0;
	Tree(const std::vector<T>& v);
	void print_tree();
	bool find_twin();
	int how_many(T E);
	int save_to_file(string filename);
private:
	void print(int level, std::ostream& output);
	Tree<T>* find(T E);
};

template <class T>
int Tree<T>::how_many(T E) {
	Tree<T>* found = find(E);
	if (found) {
		return found->count;
	} else {
		return 0;
	}
}

template <class T>
bool Tree<T>::find_twin() {
	if (count > 1) return true;
	if(left and left->find_twin()) return true;
	if(right and right->find_twin()) return true;
	return false;
}

template <class T>
Tree<T>* Tree<T>::find(T E) {
	if (key == E) return this;
	if (left and (key > E)) return left->find(E);
	if (right and (key < E)) return right->find(E);
	return 0;
}

template <class T>
void Tree<T>::print_tree() {
	print(0, cout);
}

template <class T>
int Tree<T>::save_to_file(string filename) {
	std::ofstream stream(filename, std::ios::out|std::ios::trunc);
	if(!stream) {
		return -1;
	}
	print(0, stream);
	stream.close();
	return 0;
}

template <class T>
void Tree<T>::print(int level, std::ostream& output) {
	if(left) left->print(level + 1, output);
	for(int i = 0; i< level;i++) output <<"   ";
	output << key << endl;
	if(right) right->print(level + 1, output);
}


template <class T>
Tree<T>::Tree(const std::vector<T>& v) {
	int size = v.size();
	int average = size / 2;
	key = v[average];
	count = 1;

	int left_index = average;
	while (left_index > 0 and v[left_index-1]==v[average]) {
		left_index--;
		count++;
	}

	int right_index = average;
	while (right_index < (size - 1) and v[right_index+1]==v[average]) {
		right_index++;
		count++;
	}

	if (left_index > 0) {
		vector<T> left_vector(v.begin(), (v.begin() + left_index));
		left = new Tree<T>(left_vector);
	}
	if (right_index+1 < size) {
		vector<T> right_vector((v.begin() + right_index + 1), v.end());
		right = new Tree<T>(right_vector);
	}
}

#endif /* TREE_H_ */
