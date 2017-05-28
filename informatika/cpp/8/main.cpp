/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   8/main.cpp
 * Author: pavel
 *
 * Created on 22 мая 2017 г., 14:09
 */

#include <iostream>
#include <stdio.h> // для работы с файлами
#include <cstdlib>
#include <iomanip> //setprecision
#include <cstring>
//#include <math.h>

using namespace std;

struct record
{  char name[100];
   char post[40];
   int birthday;
   float salary;
};

int file_init(const char *filename, int n) {
    int k;
    record z;
    srand(time(NULL));
    FILE *f;
    
    if ((f = fopen(filename ,"wb")) == NULL) {
        perror("error: wb");
        exit(1);
    };
    
    for( int i = 0; i < n; i++ ){
        z.name[0] = (rand() % 25) + 65;
        z.name[1] = (rand() % 25) + 65;
        z.name[2] = '\0';
        
        z.post[0] = (rand() % 25) + 65;
        z.post[1] = (rand() % 25) + 65;
        z.post[2] = (rand() % 25) + 65;
        z.post[3] = (rand() % 25) + 65;
        z.post[4] = '\0';
        
        z.birthday = (rand() % 50) + 1950;
        z.salary = (float) (rand() % 10000000) / 100 + 7000;
        fwrite(&z, sizeof(record),1,f);
    }
    fclose(f);
    return 0;
}

char answer() {
    cout << "Do you want to enter one more entry? (y/n): "; 
    char a;
    cin >> a;
    return a;
}

int file_init_user_enter(const char *filename) {
    int k;
    record z;
    FILE *f;
    
    if ((f = fopen(filename ,"ab")) == NULL) {
        perror("error: ab");
        exit(1);
    };
    
    while (answer()=='y') {
        record add;
        cout << "Enter FIO for the new entry: ";      cin >> add.name;    
        cout << "Enter post for the new entry: ";     cin >> add.post;    
        cout << "Enter birthday for the new entry: "; cin >> add.birthday;
        cout << "Enter salary for the new entry: ";   cin >> add.salary;
        fwrite(&add, sizeof(record),1,f);
    }
    fclose(f);
    return 0;
}

int file_print(const char *filename) {
    const int prec = 7;
    cout << setprecision(prec);
    record z;
    FILE *f;
    if ((f = fopen(filename ,"rb")) == NULL) {
        perror("error: rb");
        exit(1);
    };
    
    cout << "\tFIO\tPost\tBirth\tSalary\n";
    fread(&z, sizeof(record),1,f);
    while (!feof(f)) {
        cout << "\t" << z.name << "\t" << z.post << "\t" << z.birthday << "\t" << z.salary << "\n";
        fread(&z, sizeof(record),1,f);
    }
    fclose(f);
    cout << "\n\n\n";
    return 0;
}

int copy(const char *file_from_name, const char *file_to_name) {
    FILE *from, *to;
    record z;
    if ((from = fopen(file_from_name ,"rb")) == NULL) {
        perror("error: rb");
        exit(1);
    };
    if ((to = fopen(file_to_name ,"wb")) == NULL) {
        perror("error: wb");
        exit(1);
    };
    do {
        z.name[0] = '\0';
        fread(&z, sizeof(record),1,from);
        if (strlen(z.name)) {
            fwrite(&z, sizeof(record),1,to);
        }
    } while (!feof(from));
    fclose(from);
    fclose(to);
}

int del_by_key(const char *filename, char *del) {
    const char *buf_name = "temp.dat";
    FILE *f, *buf;
    record z;
    if ((f = fopen(filename ,"rb")) == NULL) {
        perror("error: rb");
        exit(1);
    };
    if ((buf = fopen(buf_name ,"wb")) == NULL) {
        perror("error: wb");
        exit(1);
    };
    
    do {
        z.name[0] = '\0';
        fread(&z, sizeof(record),1,f);
        if (strcmp(z.name,del) && strlen(z.name)) {
            fwrite(&z, sizeof(record),1,buf);
        }
    } while (!feof(f));
    fclose(f);
    fclose(buf);
    
    copy(buf_name, filename);
}

int add_after_index (const char *filename, record add, int index) {
    const char *buf_name = "temp.dat";
    FILE *f, *buf;
    record z;
    if ((f = fopen(filename ,"rb")) == NULL) {
        perror("error: rb");
        exit(1);
    };
    if ((buf = fopen(buf_name ,"wb")) == NULL) {
        perror("error: wb");
        exit(1);
    };
    
    int i = 0;
    do {
        i++;
        if (i == index) {
            fwrite(&add, sizeof(record),1,buf);
        } else {
            z.name[0] = '\0';
            fread(&z, sizeof(record),1,f);
            if (strlen(z.name)) {
                fwrite(&z, sizeof(record),1,buf);
            }
        }
    } while (!feof(f));
    fclose(f);
    fclose(buf);
    
    copy(buf_name, filename);
}

int main() {//-----------Главная функция--------------------------------------------||
    const char *file = "employees.dat"; // filename
    
// create, print
    //int n = 10; file_init(file, n);
    file_init_user_enter(file);
    file_print(file);
    
// delete by FIO
    char *del = new char;
    cout << "Enter FIO to be deleted: "; cin >> del;
    del_by_key(file,del);
    file_print(file);
    delete[] del;
    
// add record after index
    record add; int index;
    cout << "Enter FIO for the new entry: ";      cin >> add.name;    
    cout << "Enter post for the new entry: ";     cin >> add.post;    
    cout << "Enter birthday for the new entry: "; cin >> add.birthday;
    cout << "Enter salary for the new entry: ";   cin >> add.salary;  
    cout << "Enter index of the record: ";        cin >> index;       
    add_after_index(file, add, index);
    file_print(file);
}
