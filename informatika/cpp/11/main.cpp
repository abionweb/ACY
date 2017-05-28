/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   11/main.cpp
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

struct point {
    int key;
    char FIO[10];
    point *next;
};

point *point_init(const int n) {
    point *first, *p;
    first=NULL;
    for (int i=n;i>0;i--) {
        p=new(point);
        p->key=i;
        p->next=first;
        first=p;
    }
    return first;
}

point* point_fill(point *first, const int maxlengthline) {
    if (first==NULL) return NULL;
    point *p=first;
    srand(time(NULL));
    while(p!=NULL) {
        for( int j = 0; j < maxlengthline; j++) p->FIO[j] = (rand() % 25) + 65;
        p->FIO[maxlengthline] = '\0';
        p = p->next;
    }
    return first;
}

point* point_print(point *first) {
    if (first==NULL) {
        cout << "list is empty\n";
        return NULL;
    }
    point *p=first;
    while(p!=NULL) {
        cout << '\t' << p->key << '\t' << p->FIO << '\n';
        p = p->next;
    }
    cout << "\n\n";
    return first;
}

point* point_del(point *first, int del_num) {
    bool deleted = false;
    point *p=first;
    if (del_num == 1) {
        first = p->next;
        deleted = true;
    }
    while(p!=NULL) {
        if (deleted == false) {
            if (p->key+1 == del_num) {
                p->next = p->next->next;
                deleted = true;
            }
        } else {
            p->key--; 
        }        
        p = p->next;
    }
    return first;
}

point* point_add(point *first, int add_num, char *FIO) {
    bool added = false;
    point *p=first; 
    point *n;
    if (add_num == 1) {
        n=new(point);
        n->key=1;
        n->next = p;
        int i = 0;
        for (;FIO[i]!='\0'; i++) n->FIO[i] = FIO[i];
        n->FIO[i] = '\0';
        first = n;
        added = true;
    }
    while(p!=NULL) {
        if (added == false) {
            if (p->key+1 == add_num) {
                n=new(point);
                n->key=p->key+1;
                n->next = p->next;
                int i = 0;
                for (;FIO[i]!='\0'; i++) n->FIO[i] = FIO[i];
                n->FIO[i] = '\0';
                p->next = n;
                p = p->next;
                added = true;
            }
        } else {
            p->key++; 
        }        
        p = p->next;
    }
    return first;
}

point* point_save(point *first, const char *filename) {
    if (first==NULL) {
        cout << "list is empty";
        return NULL;
    }
    
    FILE *file;
    if ((file = fopen(filename ,"wb")) == NULL) {
        perror("error: wb");
        return first;
    };
    
    point *p=first;
    while(p!=NULL) {
        fwrite(p, sizeof(point),1,file);
        p = p->next;
    }
    fclose(file);
    return first;
}

point* point_remove(point *first) {
    if (first==NULL) {
        cout << "list is empty";
        return NULL;
    }
    point *p=first;
    point *p_next;
    while(p!=NULL) {
        p_next = p->next;
        delete p; //удаление указателя
        p->next = (point *)0x0;
        p = p_next;
    }
    return (point *)0x0;
}

point* point_backup(point *first, const char *filename) {
    FILE *file;
    if ((file = fopen(filename ,"rb")) == NULL) {
        perror("error: rb");
        exit(1);
    };
    point *p = new(point);
    fread(p, sizeof(point),1,file);
    first = p;
    while (!feof(file)) {
        p->next = new(point);
        fread(p->next, sizeof(point),1,file);
        if (!feof(file)) {
            p = p->next;
        } else {
            delete p->next;
            p->next = (point *)0x0;
        }
    }
    fclose(file);
    return first;
}

int main() {//-----------Главная функция--------------------------------------------||
    // создание списка
    const int n = 10; // количество элементов
    point *p = point_init(n);
   
    // заполнение списка
    const int maxlengthline = 5; // длина строки FIO
    point_fill(p, maxlengthline);
    // 1 печать списка
    point_print(p);
    
    // удаление элемента с заданным ключом
    int del_num;
    cout << "Enter the number of the element to remove: "; cin >> del_num;
    p = point_del(p, del_num);
    // 2 печать списка
    point_print(p);
    
    // добавление элемента
    char add_FIO[10];
    int add_num;
    cout << "Enter position: "; cin >> add_num;
    cout << "Enter FIO: "; cin >> add_FIO;
    p = point_add(p, add_num, add_FIO);
    // 3 печать списка
    point_print(p);
    
    // запись списка в файл
    const char *filename = "list.dat";
    p = point_save(p, filename);
    
    // уничтожение списка
    p = point_remove(p);
    point_print(p);
    
    //восстановление списка из файла
    p = point_backup(p, filename);
    point_print(p);
    
    p = point_remove(p);
}