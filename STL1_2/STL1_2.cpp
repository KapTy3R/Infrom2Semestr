#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int> numbers) {
	for (int num : numbers) {
		std::cout << num << " ";
	}
}

int main() {
	using namespace std;
	vector<int> numbers = { 2, 5, 8, 10, 15, 20 };
	int x;
	cout << "Enter X:";
	cin >> x;

	//Удаление всех элементов, кратных X
	numbers.erase(
		remove_if(numbers.begin(), numbers.end(), [x](int num) {
		return num % x == 0;}), 
	numbers.end());
	cout << "\nRemoving all elements multiple of X. Result:\n";
	print(numbers);

	//Вставка нового элемента после каждого максимального элемента
	int maxElement = *max_element(numbers.begin(), numbers.end());
	vector<int>::iterator it = numbers.begin();
	while (it != numbers.end()) {
		if (*it == maxElement) {
			++it;
			it = numbers.insert(it, maxElement + 1);
		}
		++it;
	}
	cout << "\nInserting a new element after each maximal element. Result:\n";
	print(numbers);


	// Замена всех нечетных элементов на минимальный элемент
	int minElement = *min_element(numbers.begin(), numbers.end());
	replace_if(numbers.begin(), numbers.end(), [](int num) {
		return num % 2 != 0;
		}, minElement);
	cout << "\nReplacing all odd elements with the minimum element. Result:\n";
	print(numbers);

	cout << "\n\nFinal result: ";
	print(numbers);
}