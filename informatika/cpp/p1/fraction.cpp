#include "fraction.h"
#include <iostream>

using namespace std;

int fraction::Init(int denomination, int count) {
    switch (denomination) {
        case 1:
        case 2:
        case 5:
        case 10:
        case 50:
        case 100:
        case 500:
        case 1000:            
        case 5000:            
            first = denomination;
            second = count;
            break;
        default:
            cout << "\nThis denomination does not exist!\n";
            return 1;
    }
    return 0;
}
int fraction::Read() {
    int denomination;
    cout << "Enter denomination: "; cin >> denomination;
    switch (denomination) {
        case 1:
        case 2:
        case 5:
        case 10:
        case 50:
        case 100:
        case 500:
        case 1000:            
        case 5000:
            first = denomination;
            cout << "Enter count: "; cin >> second;
            break;
        default:
            cout << "\nThis denomination does not exist!\n";
            return 1;
    }
    return 0;
}
void fraction::Show() {
    cout << "Denomination: " << first << '\n';
    cout << "Count: " << second << '\n';
}
int fraction::summa() {
    return first * second;
}