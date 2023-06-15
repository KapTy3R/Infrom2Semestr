#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
	using namespace std;
	vector<int> numbers = { 2, 5, 8, 10, 15, 20 };
	int a, b;

	//интервалы не строгие
	cout << "Enter start interval (a): "; 
	cin >> a;

	cout << "Enter end interval (b): ";
	cin >> b;

	int sum = accumulate(numbers.begin(), numbers.end(), 0, [=](int acc, int num) { //прибавляем к нулю, захватываем значения из внешнего в acc и num
			if (num < a || num > b) {
				return acc + num;
			}
			return acc;
		}
	);

	cout << "The sum of elements that do not fall in the interval [" << a << ", " << b << "]: " << sum << endl;
}