#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"
#include "Task5.h"

using namespace std;

int main() {
	Task1 t1;
	t1.show();

	Task2 t2;
	t2.show();

	Task3 <float> t31(3);
	t31.show();
	Task3 <Time> t32(3);
	t32.show();

	Task4 t4;
	t4.show();

	Task5 t5;
	t5.show();
}
