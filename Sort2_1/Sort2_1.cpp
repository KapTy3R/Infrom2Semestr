#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

void heap(std::vector<int>& row, int n, int i)
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
		std::swap(row[i], row[largest]);
		heap(row, n, largest);
	}
}

void heapSortRow(std::vector<int>& row)
{
	int n = row.size();

	for (int i = n / 2 - 1; i >= 0; i--)
		heap(row, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		std::swap(row[0], row[i]);
		heap(row, i, 0);
	}
}

int main()
{
	std::ifstream inputFile("Text.txt");
	std::ofstream outputFile("SortedText.txt");

	std::vector<std::vector<int>> arr;
	std::vector<int> row;
	std::string line;
	int num;

	// Чтение массива из файла
	while (std::getline(inputFile, line))
	{
		std::istringstream iss(line);
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
	std::vector<std::vector<int>> transposedArr(n, std::vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			transposedArr[i][j] = arr[j][i];
		}
	}

	// Сортировка строк
	for (int i = 0; i < n; i++)
	{
		heapSortRow(transposedArr[i]);
	}

	// Транспонирование матрицы обратно
	std::vector<std::vector<int>> sortedArr(n, std::vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sortedArr[j][i] = transposedArr[i][j];
		}
	}

	// Запись отсортированной матрицы в файл
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			outputFile << sortedArr[i][j] << " ";
		}
		outputFile << std::endl;
	}

	outputFile.close();

	std::cout << "Sorted array has been written to SortedText.txt" << std::endl;

	return 0;
}
