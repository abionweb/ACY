#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
#include "file_work.h"

using namespace std;

int main() {
	Time x, x1, x2;
	int k, c, nom;
	char file_name[30];
	do {
		cout << "\n1. Make file";
		cout << "\n2. Print file";
		cout << "\n3. Delete record from file";
		cout << "\n4. Add record to file";
		cout << "\n5. Change record in file";
		cout << "\n6. Delete all records a value that is not equal to the specified value";
		cout << "\n7. Reduce all records with the specified value for 1 minute 30 seconds";
		cout << "\n8. Add more entries to the beginning";
		cout << "\n0. Exit\n";
		cin >> c;

		switch(c) {
			case 1:
				cout << "Enter file name: "; cin>>file_name;
				k = make_file(file_name);
				if(k<0) cout << "Can`t make file";
				break;
			case 2:
				cout << "Enter file name: "; cin >> file_name;
				k = print_file(file_name);
				if(k==0) cout << "empty file \n";
				if(k<0) cout << "Can`t read file\n";
				break;
			case 3:
				cout << "Enter file name: "; cin >> file_name;
				cout << "Enter the number of the item to be deleted: "; nom = 0; cin >> nom;
				k = del_file(file_name, nom);
				if (k < 0) cout << "Can`t read file";
				break;
			case 4:
				cout << "Enter file name: "; cin >> file_name;
				cout << "Enter the item number? "; cin >> nom;
				cout << "New time: ";
				cin >> x1;
				k = add_file(file_name, nom, x1);
				if(k<0) cout << "Can`t read file";
				if(k == 0) k = add_end(file_name, x1);
				break;
			case 5:
				cout << "Enter file name: "; cin >> file_name;
				cout << "Enter the number of the element to be changed: "; nom = 0; cin >> nom;
				cout << "New time:"; cin >> x2;
				k = change_file(file_name, nom, x2);
				if(k < 0) cout << "\nCan`t read file";
				if(k == 0) cout << "\nNot such record";
				break;
			case 6:
				cout << "Enter file name: "; cin >> file_name;
				cout << "Enter a value that you do not want to delete: "; cin >> x1;
				k = delete_value(file_name, x1);
				if(k == 0) cout << "\nThere were no matches";
				if(k > 0) cout << "\nThere were " << k << " matches in the file";
				break;
			case 7:
				cout << "Enter file name: "; cin >> file_name;
				cout << "Enter a value that you do not want to reduce: "; cin >> x1;
				k = reduce_value(file_name, x1);
				if(k == 0) cout << "\nThere were no matches";
				if(k > 0) cout << "\nThere were " << k << " matches in the file";
				break;
			case 8:
				cout << "Enter file name: "; cin >> file_name;
				cout << "How many entries are added to the beginning of the file: "; cin >> nom;
				k = add_few(file_name, nom);
				break;
		}
	} while (c!=0);
	return 0;
}
