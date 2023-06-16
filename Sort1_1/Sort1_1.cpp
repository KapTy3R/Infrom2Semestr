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

void splitDateOfBirth(const string& dateOfBirth, string& day, string& month, string& year) {
	istringstream iss(dateOfBirth);
	getline(iss, day, '.');
	getline(iss, month, '.');
	getline(iss, year, '.');
}

//сравнение
int compareEmployees(const Employee& emp1, const Employee& emp2) {
	int surnameComparison = emp1.surname.compare(emp2.surname);
	if (surnameComparison != 0) {
		return surnameComparison;
	}

	if (emp1.experience != emp2.experience) {
		return emp1.experience - emp2.experience;
	}

	string day1, month1, year1;
	string day2, month2, year2;
	splitDateOfBirth(emp1.dateOfBirth, day1, month1, year1);
	splitDateOfBirth(emp2.dateOfBirth, day2, month2, year2);

	if (year1 != year2) {
		return year1.compare(year2);
	}

	if (month1 != month2) {
		return month1.compare(month2);
	}

	return day1.compare(day2);
}

void insertionSort(vector<Employee>& employees) {
	int n = employees.size();
	for (int i = 1; i < n; i++) {
		Employee key = employees[i];
		int j = i - 1;
		while (j >= 0 && compareEmployees(employees[j], key) > 0) {
			employees[j + 1] = employees[j];
			j--;
		}
		employees[j + 1] = key;
	}
}





int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	ifstream inputFile("text.txt");
	vector<Employee> employees;
	do {
		cout << "Enter number of sorts\n1 - Gnome\n2 - Insertion\n";
		cin >> n;
	} while (n != 1 && n != 2);
	
	string line;
	while (getline(inputFile, line)) {
		istringstream iss(line);
		Employee employee;
		iss >> employee.surname >> employee.position >> employee.dateOfBirth >> employee.experience >> employee.salary;
		employees.push_back(employee);
	}
	inputFile.close();

	if (n == 1)
		gnomeSort(employees);
	else insertionSort(employees);

	ofstream outputFile("sorted_employees.txt");

	for (const auto& employee : employees) {
		outputFile << employee.surname << " " << employee.position << " " << employee.dateOfBirth << " "
			<< employee.experience << " " << employee.salary << endl;
	}

	outputFile.close();
	cout << "Done";
}
