#include <iostream>
#include <cstdlib> // srand() и rand()
#include <time.h>

using namespace std;

void change_rows(int* &a, int* &b) {
	int* tmp = a;
	a = b;
	b = tmp;
}

void show_arr(int** A, int N, int M) { 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j] << "    ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	const int N=10, M=5;
	int** A;
	srand(time(NULL));
	//создаем массив
	A = new int* [N];
	for (int i=0; i<N; i++)
		A[i] = new int [M];
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[i][j] = rand() % 10;
		}
	}
	// вывод
	show_arr(A,N,M); 
	cout << "Sort the array by 3 column." << endl << endl;
	// сортировка
	for (int i = 1;i < N;){
        if (A[i-1][2] > A[i][2]){
            change_rows(A[i-1],A[i]);
            i--;
        }
        else i++;        
        if(i == 0) i++;            
    }
	
	// вывод
	show_arr(A,N,M); 
	
}
