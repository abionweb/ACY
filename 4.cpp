#include <iostream>
#include <cstdlib> // содержит srand() и rand()
#include <time.h> //time
using namespace std;

int main() {
	srand(time(NULL));
	int N=1000, M[N], i, j, n, K;
	cout << "Enter the length of the array: ";
	cin >> n;
	K = -1;
	
	for (i = 0; i < n; i++) {
		M[i] = rand() % 5; //Задание 1: Сформировать одномерный массив целых чисел, используя датчик случайных чисел.
		cout << "M[" << i << "]: " << M[i]; // Задание 2: распечатать полученный массив.
		if (not( K + 1 ) and ( not M[i])) { // Ищем первый элемент равный 0 для задания 3.
			K = i;
			cout << " <------";
		}
		cout << endl;
	}
	cout << endl;

	// Задание 3: удалить первый элемент равный 0.
	if ( K + 1 ) {
		cout << "delete M[" << K << "]" << endl;
		for (i = K; i < n; i++)	M[i] = M[i + 1];
		--n;
	} else {
		cout << "No element of 0" << endl;
	}
	for (i = 0; i < n; i++) cout << "M[" << i << "]: " << M[i] << endl;
	cout << endl;
	
	
	// Задание 4: добавить после каждого четного элемента массива элемент со значением M[ I-1 ]+2
	cout << "Adding after each even element of the array element with a value of M[ I-1 ]+2" << endl;
	for (i = n-1; i > 1; i--) {
		if (  i % 2 == 0 ) {
			for (j = n; j > i+1; j--) M[j] = M[j-1]; // Сдвигаем последующие элементы
			n++; 
			*(M+i+1) = *(M+i-1)+2;
		}
	}
	
	// Задание 5: распечатать получившийся массив.
	for (i = 0; i < n; i++) cout << "M[" << i << "]: " << M[i] << endl;
	cout << endl;
}
