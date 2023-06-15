#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;

	Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
	Node* top;

public:
	Stack() : top(nullptr) {}

	~Stack() {
		while (!isEmpty()) {
			pop();
		}
	}

	void push(int value) {
		Node* newNode = new Node(value);
		if (isEmpty()) {
			top = newNode;
		}
		else {
			newNode->next = top;
			top = newNode;
		}
	}

	void pop() {
		if (isEmpty()) {
			cout << "Stack is empty. Cannot pop." << endl;
			return;
		}

		Node* temp = top;
		top = top->next;
		delete temp;
	}

	int peek() {
		if (isEmpty()) {
			cout << "Stack is empty. No element to peek." << endl;
			return -1;
		}

		return top->data;
	}

	bool isEmpty() {
		return (top == nullptr);
	}

	void removeDuplicates() {
		if (isEmpty()) {
			return;
		}

		Node* current = top;
		while (current != nullptr) {
			Node* runner = current;
			while (runner->next != nullptr) {
				if (runner->next->data == current->data) {
					Node* duplicate = runner->next;
					runner->next = runner->next->next;
					delete duplicate;
				}
				else {
					runner = runner->next;
				}
			}
			current = current->next;
		}
	}

	void sortStack() {
		if (isEmpty() || top->next == nullptr) {
			return;
		}

		Node* current = top;
		while (current != nullptr) {
			Node* nextNode = current->next;
			while (nextNode != nullptr) {
				if (current->data > nextNode->data) {
					int temp = current->data;
					current->data = nextNode->data;
					nextNode->data = temp;
				}
				nextNode = nextNode->next;
			}
			current = current->next;
		}
	}

	void display() {
		Node* temp = top;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	Stack stack;
	int n;
	cout << "Enter the number of numbers:" << endl;
	cin >> n;
	cout << "\nEnter numbers:" << endl;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		stack.push(num);
	}

	cout << "Stack before removing duplicates: ";
	stack.sortStack();
	stack.display();

	stack.removeDuplicates();
	cout << "Stack after removing duplicates: ";
	stack.sortStack();
	stack.display();
}
