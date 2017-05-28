/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   9/main.cpp
 * Author: pavel
 *
 * Created on 23 мая 2017 г., 14:09
 */

#include <iostream>
#include <stdio.h> // для работы с файлами
#include <cstdlib>
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
    int maxline = 6;
    char txt[maxline+2];
    srand(time(NULL));
    FILE *f1;
    
    if ((f1 = fopen(filename ,"w")) == NULL) {
        perror("error: w");
        exit(1);
    };
    
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < maxline; j++) txt[j] = (rand() % 5) + 65;
        txt[maxline] = '\n';
        txt[maxline+1]   = '\0';
        fputs(txt,f1);
    }
    fclose(f1);
    return 0;
}

int file_print(const char *filename) {
    FILE *f;
    int maxline = 7;
    char txt[maxline];
    
    if ((f = fopen(filename ,"r")) == NULL) {
        perror("error: rb");
        exit(1);
    };
    
    while (fgets(txt, maxline, f) != NULL) {
        cout << txt;
    }
    
    fclose(f);
    cout << "\n";
    return 0;
}

int file_copy_first_A(const char *filename1, const char *filename2) {
    FILE *f1, *f2;
    int maxline = 7;
    char buf[maxline+2];
    
    if ((f1 = fopen(filename1 ,"r")) == NULL) {
        perror("error: rb");
        exit(1);
    };
    if ((f2 = fopen(filename2 ,"w")) == NULL) {
        perror("error: w");
        exit(1);
    };
    while (fgets (buf, maxline+2, f1)!=NULL) {
        if (buf[0] == 'A') {
            fputs(buf,f2);
        }
    }
    fclose(f1);
    fclose(f2);
}

int main() {//-----------Главная функция--------------------------------------------||
    const char *f1 = "f1.txt"; // filename
    const char *f2 = "f2.txt";
    int n = 10; // record count
    file_init(f1, n);
    file_print(f1);
    file_copy_first_A(f1,f2);
    file_print(f2);
}