#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;
/*

Алгоритм Тарьяна - это алгоритм для поиска сильно связных компонент в ориентированном графе. 
Он использует обход в глубину (DFS) и основан на понятиях "идентификаторов" и "нижних пределов" для каждой вершины. 
Алгоритм строит стек посещенных вершин и находит сильно связные компоненты, когда идентификатор и нижний предел вершины равны. 
Алгоритм повторяется для каждой непосещенной вершины, пока не пройдет все вершины графа.
*/


// Функция обхода в глубину с использованием алгоритма Тарьяна
void tarjanDFS(int node, unordered_map<int, vector<int>>& graph, vector<bool>& visited, vector<int>& ids, vector<int>& lowLink, stack<int>& st, vector<bool>& onStack, vector<vector<int>>& sccs, int& id) {
	visited[node] = true;
	st.push(node);
	onStack[node] = true;
	ids[node] = lowLink[node] = id++;

	// Обработка всех смежных вершин
	for (int neighbor : graph[node]) {
		if (!visited[neighbor]) {
			// Рекурсивный вызов для непосещенных смежных вершин
			tarjanDFS(neighbor, graph, visited, ids, lowLink, st, onStack, sccs, id);
			lowLink[node] = min(lowLink[node], lowLink[neighbor]);
		}
		else if (onStack[neighbor]) {
			// Обновление lowLink для вершины, находящейся на стеке
			lowLink[node] = min(lowLink[node], ids[neighbor]);
		}
	}

	// Если текущая вершина является началом сильно связной компоненты
	if (ids[node] == lowLink[node]) {
		vector<int> scc;
		int curr;
		do {
			// Извлечение вершин из стека и добавление их в компоненту
			curr = st.top();
			st.pop();
			onStack[curr] = false;
			scc.push_back(curr);
		} while (curr != node);

		// Добавление сильно связной компоненты в результаты
		sccs.push_back(scc);
	}
}

// Функция поиска всех сильно связных компонент графа
vector<vector<int>> findStronglyConnectedComponents(unordered_map<int, vector<int>> & graph) {
	int n = graph.size();
	vector<bool> visited(n, false);
	vector<int> ids(n, -1);
	vector<int> lowLink(n, -1);
	stack<int> st;
	vector<bool> onStack(n, false);
	vector<vector<int>> sccs;
	int id = 0;

	// Вызов обхода в глубину для каждой непосещенной вершины
	for (auto& entry : graph) {
		int node = entry.first;
		if (!visited[node]) {
			tarjanDFS(node, graph, visited, ids, lowLink, st, onStack, sccs, id);
		}
	}

	return sccs;
}

int main() {
	unordered_map<int, vector<int>> graph = {
		{0, {1, 3}},
		{1, {2}},
		{2, {0, 4}},
		{3, {2}},
		{4, {}},
		{5, {}}
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

	// Поиск сильно связных компонент
	vector<vector<int>> sccs = findStronglyConnectedComponents(graph);

	// Вывод результатов
	cout << "Strongly Connected Components:\n";
	for (const auto& scc : sccs) {
		for (int node : scc) {
			cout << node << " ";
		}
		cout << endl;
	}
}
