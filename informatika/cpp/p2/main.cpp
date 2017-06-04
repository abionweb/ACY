#include "book.h"
#include <cstdlib>
#include <string>

using namespace std;

book make_book() {
    string t;
    string g;
    float a;
    cout << "Enter title: "; cin >> t;
    cout << "Enter group: "; cin >> g;
    cout << "Enter average score: "; cin >> a;
    book b(t,g,a);
    return b;
}

void print_book(book b) {
    b.show();
}

int main(int argc, char** argv) {
    book b1;
    b1.show();
    
    book b2("Informatika", "Ychebnik", 5);
    b2.show();
    
    book b3 = b2;
    b3.set_title("Programmirovanie");
    b3.set_group("uchebnik dlia vuzov");
    b3.set_average_score(6);
    
    print_book(b3);
    
    b1 = make_book();
    b1.show();    
    return 0;
}

