#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

void heap(vector<int>& row, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && row[l] > row[largest])
		largest = l;

	if (r < n && row[r] > row[largest])
		largest = r;

	if (largest != i)
	{
		swap(row[i], row[largest]);
		heap(row, n, largest);
	}
}

void heapSort(vector<int>& row)
{
	int n = row.size();

	for (int i = n / 2 - 1; i >= 0; i--)
		heap(row, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(row[0], row[i]);
		heap(row, i, 0);
	}
}

int main()
{
	ifstream inputFile("Text.txt");
	ofstream outputFile("SortedText.txt");

	vector<vector<int>> arr;
	vector<int> row;
	string line;
	int num;

	// Чтение массива из файла
	while (getline(inputFile, line))
	{
		istringstream iss(line);
		while (iss >> num)
		{
			row.push_back(num);
		}
		arr.push_back(row);
		row.clear();
	}

	inputFile.close();

	int n = arr.size(); // Размерность массива

	// Транспонирование матрицы
	vector<vector<int>> tArr(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tArr[i][j] = arr[j][i];
		}
	}

	// Сортировка строк
	for (int i = 0; i < n; i++)
	{
		heapSort(tArr[i]);
	}

	// Транспонирование матрицы обратно
	vector<vector<int>> sArr(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sArr[j][i] = tArr[i][j];
		}
	}

	// Запись отсортированной матрицы в файл
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			outputFile << sArr[i][j] << " ";
		}
		outputFile << endl;
	}

	outputFile.close();

	cout << "Done" << endl;
}
