#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;

	Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
	Node* head;
	int size;

public:
	LinkedList() : head(nullptr), size(0) {}

	~LinkedList() {
		while (!isEmpty()) {
			removeFirst();
		}
	}

	void addElement(int value) {
		Node* newNode = new Node(value);
		if (isEmpty()) {
			head = newNode;
		}
		else {
			Node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
		}
		size++;
	}

	void removeFirst() {
		if (isEmpty()) {
			cout << "List is empty. Cannot remove." << endl;
			return;
		}

		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}

	double getAverage(Node* start) {
		if (start == nullptr || start->next == nullptr) {
			return 0.0;
		}

		Node* current = start->next;
		int count = 0;
		double sum = 0.0;

		while (current != nullptr) {
			sum += current->data;
			count++;
			current = current->next;
		}

		return sum / count;
	}

	void removeExtraElements() {
		if (isEmpty() || size == 1) {
			return;
		}

		Node* current = head;

		while (current != nullptr && current->next != nullptr) {
			double average = getAverage(current);

			if (current->next->data > average) {
				Node* temp = current->next;
				current->next = current->next->next;
				delete temp;
				size--;
			}
			else {
				current = current->next;
			}
		}
	}

	bool isEmpty() {
		return (head == nullptr);
	}

	void display() {
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	LinkedList list;
	int n;
	cout << "Enter the number of numbers:" << endl;
	cin >> n;
	cout << "\nEnter numbers:" << endl;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		list.addElement(num);
	}

	cout << "Start elements: ";
	list.display();

	list.removeExtraElements();
	cout << "List after removing extra elements: ";
	list.display();
}
