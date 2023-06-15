#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* left; // потомоки
	Node* right;

	Node(int val) : value(val), left(nullptr), right(nullptr) {} // Конструктор, который устанавливает значение узла при его создании
};

// Функция для вставки элемента в дерево
Node* insert(Node* root, int value) {
	if (root == nullptr) {
		return new Node(value);
	}

	if (value < root->value) {
		root->left = insert(root->left, value);
	}
	else {
		root->right = insert(root->right, value);
	}

	return root;
}

// Функция для слияния двух поддеревьев
Node* merge(Node* left, Node* right) {
	if (left == nullptr) {
		return right;
	}
	if (right == nullptr) {
		return left;
	}

	// Находим самый правый узел в левом поддереве
	Node* current = left;
	while (current->right != nullptr) {
		current = current->right;
	}

	// Присоединяем правое поддерево к самому правому узлу левого поддерева
	current->right = right;

	return left;
}


// Функция для прямого обхода дерева и выполнения операций над значениями
Node* preOrderTraversal(Node* root, int x) {
	if (root == nullptr) {
		return nullptr;
	}

	// Рекурсивно вызываем обход для левого и правого поддерева
	root->left = preOrderTraversal(root->left, x);
	root->right = preOrderTraversal(root->right, x);

	// Выполняем операции над значением узла
	if (root->value % x == 0) {
		// Удаляем узел, кратный X
		Node* left = root->left;
		Node* right = root->right;
		delete root;
		return merge(left, right);
	}

	return root;
}


// Функция для вывода элементов дерева
void printTree(Node* root) {
	if (root == nullptr) {
		return;
	}

	cout << root->value << " ";
	printTree(root->left);
	printTree(root->right);
}

int main() {
	// Создание дерева
	Node* root = nullptr;

	// Вставка элементов в дерево
	root = insert(root, 8);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 2);
	root = insert(root, 7);
	root = insert(root, 10);
	root = insert(root, 14);

	// Вывод изначального дерева в порядке их обхода
	cout << "Start tree: ";
	printTree(root);
	cout << endl;

	int x=2;
	// Прямой обход дерева и удаление элементов, кратных X
	root = preOrderTraversal(root, x);

	// Вывод элементов нового дерева
	cout << "End Tree: ";
	printTree(root);
	cout << endl;
}
