//Made by Anna Kravets, K-22
#include <iostream>
#include "E:\2 курс\Lab1\my_random\my_random.h"
#include <string>
using namespace std;

void printMenu() {
	string methods[10] = { "Linear", "Square", "Fibbo", "Reverse",
	"Combination", "3-sigma", "Polar coordinates", "Fraction",
	"Logarithm", "Arens'" };
	cout << "Enter one of the following numbers to choose your method:\n";
	for (int i = 0; i < 10; i++) {
		cout << i + 1 << " - " << methods[i] << "\n";
	}
}

//pre: 0<v<6
void histogram(int v) {
	double g[100] = {}, z;
	for (int i = 0; i < nElem; i++) {
		switch (v) {
		case 1:
			z=nextLinearDouble();
			break;
		case 2:
			z=nextSquareDouble();
			break;
		case 3:
			z=nextFibboDouble();
			break;
		case 4:
			z=nextReverseDouble();
			break;
		case 5:
			z=nextCombinationDouble();
			break;
		case 6:
			z = nextSigmaMethod();
			break;
		case 7:
			z = nextPolar();
			break;
		case 8:
			z = nextFraction();
			break;
		case 9:
			z = nextLogarithmMethod();
			break;
		case 10:
			z = nextArens();
			break;
		default:
			throw exception("Mistake: You can enter only 1, 2.. 10\n");
		}
		if (v>0 && v<6)
			g[int(z * 10.)] += 1.;
		else if (v > 5 && v<9) {
			if (z >= -3. && z <= 3.) {
				g[int((z+3.) * 10.)] += 1.;
			}
		}
		else {
			if (z>=0. && z<100.)
				g[int(z)] += 1.;
		}
	}
	for (int i = 0; i < 100; i++)
		g[i] = (g[i] / nElem)*100.;
	if (v > 0 && v < 6)
		printHistogram(g, 10, 0., 0.1);
	else if (v > 5 && v < 9)
		printHistogram(g, 60, -3., 0.1);
	else
		printHistogram(g, 100, 0., 1.);
}

int main()
{
	try {
		printMenu();
		int v;
		while (cin >> v) {
			histogram(v);
			printMenu();
		}
	}
	catch (exception &e) {
		cout << e.what() << endl;
	}
	catch(...) {
		cout << "Sorry, there is a MISTAKE\n";
	}
    return 0;
}



