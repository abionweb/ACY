/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   10/main.cpp
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

int array_init(int *array, int count) {
    srand(time(NULL));
    for(int i = 0; i<count; i++) {
        array[i] = rand() % 99;
    }
    return 0;
}

int array_print(int *array, int count) {
    for(int i = 0; i<count; i++) {
        cout << array[i] << "  ";
    }
    cout << "\n\n";
    return 0;
}

int array_del(int *array, int *count, int del_key) {
    for(int i = del_key-1; i<*count-1; i++) {
        array[i] = array[i+1];
    }
    (*count)--;
    return 0;
}

int array_add(int *array, int *count, int add_key, int add_value) {
    (*count)++;
    for(int i = *count-1; i>=add_key; i--) {
        array[i] = array[i-1];
    }
    array[add_key-1] = add_value;
    return 0;
}

int main() {//-----------Главная функция--------------------------------------------||
    int count; // record count
    cout << "Enter the size of the array: "; cin >> count;
    
    int *array = new int[count];
    
    array_init(array, count);
    array_print(array, count);
    
    int del_key;
    cout << "Enter the number of the element to remove: "; cin >> del_key;
    array_del(array, &count, del_key);
    array_print(array, count);
    
    int add_value; int add_key;
    cout << "Enter the number of the element to add: "; cin >> add_key;
    cout << "Enter the value of the element to add: "; cin >> add_value;
    array_add(array, &count, add_key, add_value);
    array_print(array, count);
    
    delete[] array;
}