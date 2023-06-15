#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	using namespace std;
	vector<int> numbers = { 2, 5, 8, 10, 15, 20 };

	vector<int> res;
	for_each(numbers.begin(), numbers.end(), [&res](int num) {
		if (num >= 10 && num <= 99) {
			while (num > 0) {
				int digit = num % 10;
					res.push_back(digit);
				num /= 10;
			}
		}
		});

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	
	cout << "Numbers that occur only in two-digit numbers: ";
	for (int digit : res) {
		cout << digit << " ";
	}
}
