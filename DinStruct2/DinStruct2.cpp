#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

struct Node {
	char* data;
	Node* next;

	Node(const char* value) : next(nullptr) {
		data = new char[strlen(value) + 1];
		strcpy(data, value);
	}

	~Node() {
		delete[] data;
	}
};

class Queue {
private:
	Node* front;
	Node* rear;

public:
	Queue() : front(nullptr), rear(nullptr) {}

	~Queue() {
		while (!isEmpty()) {
			dequeue();
		}
	}

	void enqueue(const char* value) {
		Node* newNode = new Node(value);
		if (isEmpty()) {
			front = newNode;
			rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
	}

	void dequeue() {
		if (isEmpty()) {
			std::cout << "Queue is empty. Cannot dequeue." << std::endl;
			return;
		}

		Node* temp = front;
		front = front->next;
		if (front == nullptr) {
			rear = nullptr;
		}
		delete temp;
	}

	bool isEmpty() {
		return (front == nullptr);
	}

	void removeDuplicates() {
		if (isEmpty() || front == rear) {
			return;
		}

		Node* current = front;
		while (current != nullptr) {
			Node* runner = current;
			while (runner->next != nullptr) {
				if (strcmp(runner->next->data, current->data) == 0) {
					Node* duplicate = runner->next;
					runner->next = runner->next->next;
					if (runner->next == nullptr) {
						rear = runner;
					}
					delete duplicate;
				}
				else {
					runner = runner->next;
				}
			}
			current = current->next;
		}
	}

	void display() {
		Node* temp = front;
		while (temp != nullptr) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
};

int main() {
	Queue queue;

	std::cout << "Enter words (enter an empty word to stop):" << std::endl;
	char word[100];
	std::cin.getline(word, sizeof(word));
	while (strcmp(word, "") != 0) {
		queue.enqueue(word);
		std::cin.getline(word, sizeof(word));
	}

	queue.removeDuplicates();

	std::cout << "Queue after removing duplicates: ";
	queue.display();

	return 0;
}

