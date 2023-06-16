#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// Структура элемента очереди
struct QueueNode {
	char word[100];
	QueueNode* next;
};

// Структура очереди
struct Queue {
	QueueNode* front;
	QueueNode* rear;
};

// Инициализация очереди
void initQueue(Queue& q) {
	q.front = nullptr;
	q.rear = nullptr;
}

// Проверка, является ли очередь пустой
bool isQueueEmpty(Queue& q) {
	return (q.front == nullptr);
}

// Вставка элемента в очередь
void enqueue(Queue & q, const char* word) {
	QueueNode* newNode = new QueueNode;
	strcpy(newNode->word, word);
	newNode->next = nullptr;

	if (isQueueEmpty(q)) {
		q.front = newNode;
		q.rear = newNode;
	}
	else {
		q.rear->next = newNode;
		q.rear = newNode;
	}
}

// Удаление элемента из очереди
void dequeue(Queue & q) {
	if (isQueueEmpty(q)) {
		cout << "Queue is empty." << endl;
		return;
	}

	QueueNode* temp = q.front;
	q.front = q.front->next;
	delete temp;
}

// Удаление из очереди всех слов, совпадающих с последним словом
void removeMatchingWords(Queue & q) {
	if (isQueueEmpty(q)) {
		cout << "Queue is empty." << endl;
		return;
	}

	const char* lastWord = q.rear->word;

	QueueNode* curr = q.front;
	QueueNode* prev = nullptr;

	while (curr != nullptr) {
		if (strcmp(curr->word, lastWord) == 0) {
			if (curr == q.front) {
				q.front = curr->next;
			}
			else {
				prev->next = curr->next;
			}

			if (curr == q.rear) {
				q.rear = prev;
			}

			QueueNode* temp = curr;
			curr = curr->next;
			delete temp;
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
}

// Преобразование слова к нижнему регистру
void toLowercase(char* word) {
	int length = strlen(word);
	for (int i = 0; i < length; i++) {
		word[i] = tolower(word[i]);
	}
}

// Преобразование всех слов в очереди к нижнему регистру
void convertWordsToLowercase(Queue & q) {
	if (isQueueEmpty(q)) {
		cout << "Queue is empty." << endl;
		return;
	}

	QueueNode* curr = q.front;

	while (curr != nullptr) {
		toLowercase(curr->word);
		curr = curr->next;
	}
}

// Вывод содержимого очереди
void displayQueue(Queue & q) {
	if (isQueueEmpty(q)) {
		cout << "Queue is empty." << endl;
		return;
	}

	QueueNode* curr = q.front;

	while (curr != nullptr) {
		cout << curr->word << " ";
		curr = curr->next;
	}

	cout << endl;
}

int main() {
	Queue wordQueue;
	initQueue(wordQueue);

	int numWords;
	cout << "Enter the number of words: ";
	cin >> numWords;

	cout << "Enter " << numWords << " words:" << endl;
	for (int i = 0; i < numWords; i++) {
		char word[100];
		cin >> word;
		enqueue(wordQueue, word);
	}

	cout << "Original queue: ";
	displayQueue(wordQueue);

	convertWordsToLowercase(wordQueue);

	cout << "Queue after converting words to lowercase: ";
	displayQueue(wordQueue);

	removeMatchingWords(wordQueue);

	cout << "Queue after removing matching words: ";
	displayQueue(wordQueue);

	return 0;
}

