#include<iostream>
#include<cmath>
using namespace std;

void print(int n, char a) { //печать n символов a
	for (int i = 0; i < n; i++)
		cout << a;
}

void F(int p, int n, char a) { // p - пробелов, n - символов
	if (n > 0) {
		print(p, ' ');
		print(n, a);
		cout << endl;
		F(p+1, n-2, a);
	}
}

int main() {
	int n;
	cout << " Input n\n";
	cin >> n;

	int N = n * 2 - 1;
		if (N % 2 == 0) N--;
		int j = -1;
		for (int i = n - 1; i >= 0; i--) {
			++j;
			F(N-j, N - (i * 2), '*');
		}

}