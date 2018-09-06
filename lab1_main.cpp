//Made by Anna Kravets, K-22
#include <iostream>
#include <climits>
#include <cmath>
#include <ctime>
using namespace std;

const unsigned int maxPrime =562804;
const int nElem = 1000;

bool checkPrime(unsigned int x) {
	bool isPrime = true;
	unsigned int y = sqrt(x)+1;
	for (int xx = 2; xx <= y; xx++) {
		if (x%xx == 0) {
			isPrime = false;
			break;
		}
	}
	return isPrime;
}

void linearCongruentMethod() {
	unsigned int a = 5003, c = 60607, m = maxPrime;
	while (!checkPrime(m))
		m--;
	unsigned int arr[nElem];
	arr[0] = 3203;
	for (int i = 1; i < nElem; i++) {
		arr[i] = (a*arr[i - 1] + c) % m;
	}
	double s[nElem], d[10] = {};
	for (int i = 0; i < nElem; i++) {
		s[i] = double(arr[i]) / m;
		d[int(s[i] * 10)] += 1.;
	}
	for (int i = 0; i < 10; i++) {
		d[i] = d[i] / nElem;
		cout << d[i] << ' ';
	}
}

int main()
{
	linearCongruentMethod();
	
    return 0;
}

