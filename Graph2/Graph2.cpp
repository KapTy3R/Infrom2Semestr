#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
	int vertexToCheck;
	// Предопределенный граф в виде списка смежности
	unordered_map<int, vector<int>> graph = {
		{0, {1, 3}},
		{1, {2}},
		{2, {0, 4}},
		{3, {2}},
		{4, {1, 3}}
	};

	// Вывод исходного графа
	cout << "Default graph:\n";
	for (auto& entry : graph) {
		int vertex = entry.first;
		vector<int>& adjacentVertices = entry.second;

		cout << "Vertex " << vertex << ": ";
		for (int i = 0; i < adjacentVertices.size(); i++) {
			cout << adjacentVertices[i] << " ";
		}
		cout << endl;
	}

	cout << "\nEnter vertex: ";
	cin >> vertexToCheck; // Вершина, для которой нужно найти несмежные вершины

	// Проверка вершин, не смежных с заданной вершиной
	cout << "\nVertices not adjacent to " << vertexToCheck << " vertex:\n";
	unordered_set<int> adjacentVertices = unordered_set<int>(graph[vertexToCheck].begin(), graph[vertexToCheck].end());
	for (auto& entry : graph) {
		int vertex = entry.first;
		if (vertex != vertexToCheck && adjacentVertices.find(vertex) == adjacentVertices.end()) {
			cout << vertex << " ";
		}
	}
	cout << endl;

	return 0;
}
