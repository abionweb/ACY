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
#include <string.h>
#include <cstdlib>
#include <cstring>
//#include <math.h>

using namespace std;

int file_init(const char *filename, int n) {
    int k, maxline = 6;
    char txt[maxline+2];
    srand(time(NULL));
    FILE *f1;
    
    if ((f1 = fopen(filename ,"w")) == NULL) {
        perror("error: w");
        exit(1);
    };
    
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < maxline; j++) {
            if (rand() % 4 == 1) { txt[j] = ' '; }
                else txt[j] = (rand() % 5) + 65;
        }
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
        perror("error: r");
        exit(1);
    };
    cout << filename << ":\n-------\n";
    while (fgets(txt, maxline, f) != NULL) {
        cout << txt;
    }
    
    fclose(f);
    cout << "\n\n";
    return 0;
}

int file_copy_first_A(const char *filename1, const char *filename2) {
    FILE *f1, *f2;
    int maxline = 7;
    char buf[maxline+2];
    
    if ((f1 = fopen(filename1 ,"r")) == NULL) {
        perror("error: r");
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
    return 0;
}

int file_word_count_F2(const char *filename2) {
    FILE *f2;
    int count = 0, maxline = 7;
    char buf[maxline+2], *pstr;
    if ((f2 = fopen(filename2 ,"r")) == NULL) {
        perror("error: r");
        exit(0);
    };
    while (fgets (buf, maxline+2, f2)!=NULL) {
        pstr=strtok(buf," ");
        while ((pstr!=NULL) && (strcmp(pstr, "\n"))) {
          count++;
          pstr=strtok(NULL," ");
        }
    }
    fclose(f2);
    return count;
}

int main() {//-----------Главная функция--------------------------------------------||
    const char *f1 = "f1.txt"; // filename
    const char *f2 = "f2.txt";
    int n = 20; // record count
    file_init(f1, n);
    file_print(f1);
    file_copy_first_A(f1,f2);
    file_print(f2);
    cout << "Word count: " << file_word_count_F2(f2) << "\n";
    return 0;
}