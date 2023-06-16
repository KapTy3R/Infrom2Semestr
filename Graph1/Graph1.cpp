#include <iostream>
#include <vector>

using namespace std;

void removeVertex(vector<vector<int>>& graph, int vertex) {
	int n = graph.size();

	// Удаляем ребра, исходящие из вершины
	graph[vertex].clear();

	// Удаляем ребра, ведущие к вершине
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			if (graph[i][j] == vertex) {
				graph[i].erase(graph[i].begin() + j);
				break;
			}
		}
	}
}

int main() {
	int vertexToRemove;
	vector<vector<int>> graph = {
		{1, 2},     // Вершина 0 соединена с вершинами 1 и 2
		{0, 2, 3},  // Вершина 1 соединена с вершинами 0, 2 и 3
		{0, 1, 3},  // Вершина 2 соединена с вершинами 0, 1 и 3
		{1, 2}      // Вершина 3 соединена с вершинами 1 и 2
	};
	cout << "Default graph:\n";
	for (int i = 0; i < graph.size(); i++) {
		cout << i << ": ";
		for (int j = 0; j < graph[i].size(); j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\nEnter vertex to remove: ";
	cin >> vertexToRemove;

	removeVertex(graph, vertexToRemove);

	cout << "New graph:" << endl;
	for (int i = 0; i < graph.size(); i++) {
		cout << i << ": ";
		for (int j = 0; j < graph[i].size(); j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}
