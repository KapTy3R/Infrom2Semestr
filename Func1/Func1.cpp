#include <iostream>

int Sum(int n) {
	int s = 0;
	while (n > 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}


int main() {
	int x;

	std::cout << "Enter X: ";
	std::cin >> x;

	std::cout << "Three-digit numbers whose sum of digits is a multiple of " << x << ":\n";

	int n = 0;
	for (int n = 100; n <= 999; ++n) {
		if (Sum(n) % x == 0) {
			std::cout << n << std::endl;
		}
	}
}
