#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Employee {
	string surname;
	string position;
	string dateOfBirth;
	int experience;
	double salary;
};

void gnomeSort(vector<Employee>& employees) {
	int i = 1;
	int n = employees.size();
	while (i < n) {
		if (i == 0) {
			i++;
		}
		if (employees[i - 1].position < employees[i].position ||
			(employees[i - 1].position == employees[i].position && employees[i - 1].salary < employees[i].salary)) {
			i++;
			/*Если текущий элемент больше или равен предыдущего по ключу должности, 
			или если ключи должностей равны, но текущий элемент больше предыдущего по ключу зарплаты,
			перемещаемся к следующему элементу*/
		}
		else {
			/*Если текущий элемент меньше предыдущего по ключу должности или по ключу зарплаты,
				меняем их местами и переходим к предыдущему элементу*/
			swap(employees[i - 1], employees[i]);
			i--;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	ifstream inputFile("text.txt");
	vector<Employee> employees;

	string line;
	while (getline(inputFile, line)) {
		istringstream iss(line);
		Employee employee;
		iss >> employee.surname >> employee.position >> employee.dateOfBirth >> employee.experience >> employee.salary;
		employees.push_back(employee);
	}

	inputFile.close();

	// Сортировка данных о сотрудниках
	gnomeSort(employees);

	ofstream outputFile("sorted_employees.txt");

	for (const auto& employee : employees) {
		outputFile << employee.surname << " " << employee.position << " " << employee.dateOfBirth << " "
			<< employee.experience << " " << employee.salary << endl;
	}

	outputFile.close();
	cout << "Done";
}
