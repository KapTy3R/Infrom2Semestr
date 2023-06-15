#include<iostream>
#include<cmath>
using namespace std;

double Progress(double a, double r, int n) {
	if (n == 1) {
		return a;
	}
	else {
		return r * Progress(a, r, n - 1); // рекурсивно вычисляем N-ый член прогрессии
	}
}

int main() {
	double a, r;
	int n;

	cout << "Enter the first term of the progression (a): ";
	cin >> a;

	cout << "Enter the denominator of the progression (r): ";
	cin >> r;

	cout << "Enter the number of the progression member (n): ";
	cin >> n;

	double result = Progress(a, r, n);

	cout << "N-th term of a geometric progression: " << result << endl;
}