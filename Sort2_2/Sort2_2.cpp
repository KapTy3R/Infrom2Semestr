#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

void insertionSort(vector<int>& diagonal)
{
	for (int i = 1; i < diagonal.size(); i++)
	{
		int j = i;
		while (j > 0 && diagonal[j] < diagonal[j - 1])
		{
			swap(diagonal[j], diagonal[j - 1]);
			j--;
		}
	}
}

void sortDiagonals(vector<vector<int>> & arr)
{
	int numRows = arr.size();
	int numCols = arr[0].size();

	// Сортировка диагоналей, параллельных побочной
	for (int k = 0; k < numCols; k++)
	{
		vector<int> diagonal;
		int i = 0;
		int j = k;
		while (i < numRows && j < numCols)
		{
			diagonal.push_back(arr[i][j]);
			i++;
			j++;
		}
		insertionSort(diagonal);
		i = 0;
		j = k;
		int idx = 0;
		while (i < numRows && j < numCols)
		{
			arr[i][j] = diagonal[idx];
			i++;
			j++;
			idx++;
		}
	}

	for (int k = 1; k < numRows; k++)
	{
		vector<int> diagonal;
		int i = k;
		int j = 0;
		while (i < numRows && j < numCols)
		{
			diagonal.push_back(arr[i][j]);
			i++;
			j++;
		}
		insertionSort(diagonal);
		i = k;
		j = 0;
		int idx = 0;
		while (i < numRows && j < numCols)
		{
			arr[i][j] = diagonal[idx];
			i++;
			j++;
			idx++;
		}
	}
}

int main()
{
	ifstream inputFile("Text.txt");
	ofstream outputFile("SortedText.txt");

	vector<vector<int>> arr;
	string line;
	int num;

	// Чтение массива из файла
	while (getline(inputFile, line))
	{
		vector<int> row;
		istringstream iss(line);
		while (iss >> num)
		{
			row.push_back(num);
		}
		arr.push_back(row);
	}

	inputFile.close();

	// Сортировка диагоналей
	sortDiagonals(arr);

	// Запись отсортированного массива в файл
	for (const auto& row : arr)
	{
		for (int num : row)
		{
			outputFile << num << " ";
		}
		outputFile << endl;
	}

	outputFile.close();

	cout << "Done" << endl;
}
