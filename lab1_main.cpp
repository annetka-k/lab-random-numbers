//Made by Anna Kravets, K-22
#include <iostream>
#include "E:\2 курс\Lab1\my_random\my_random.h"
#include <string>
using namespace std;

void printMenu() {
	string methods[10] = { "Linear", "Square", "Fibbo", "Reverse",
	"Combination", "3-sigma", "Polar coordinates", "Fraction",
	"Logarithm", "Arens'" };
	for (int i = 0; i < 10; i++) {
		cout << "Enter " << i + 1 << " to use " << methods[i] << " method\n";
	}
}

int main()
{
	printMenu();
	int v;
	while (cin >> v) {
		switch (v) {
		case 1:
			linearCongruentMethod();
			break;
		case 2:
			squareCongruentMethod();
			break;
		case 3:
			fibboMethod();
			break;
		case 4:
			reverseCongruentSequence();
			break;
		default:
			cout << "Mistake: you should enter 1,2,..10\n";
		}
		printMenu();
	}
    return 0;
}



