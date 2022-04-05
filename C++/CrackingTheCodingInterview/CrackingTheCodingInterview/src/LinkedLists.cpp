#include "../include/LinkedLists.h"

#include <unordered_set>

//space O(n), time O(n)
void solution1a(Node* head) {
	std::unordered_set<int> duplicates = std::unordered_set<int>();
	Node* slow = nullptr;
	while (head != nullptr) {
		if (duplicates.count(head->data) > 0) {
			slow->next = head->next;
		}
		else {
			duplicates.insert(head->data);
			slow = head;
		}
		head = head->next;
	}
}

//space O(1), time O(n^2)
void solution1b(Node* head) {
	if (head->next == nullptr)
		return;

	while (head != nullptr && head->next != nullptr) {
		Node* runner = head;
		while (runner->next != nullptr) {
			if (runner->next->data == head->data) {
				runner->next = runner->next->next;
			}
			else {
				runner = runner->next;
			}
		}
		head = head->next;
	}
}

Node& solution2a(Node* head, int k) {
	if (k <= 0) {
		throw std::exception("Pick K thats over 0");
	}
	Node* tmp = head;

	int counter = 0;
	while (tmp != nullptr) {
		counter++;
		tmp = tmp->next;
	}

	if (counter < k) {
		throw std::exception("Pick K thats less than length of list");
	}

	for (int i = 0; i < (counter - k); i++) {
		head = head->next;
	}

	return *head;
}

Node& solution2b(Node* head, int k) {
	if (k <= 0)
		throw std::exception("Pick K thats over 0");

	Node* runner = head;

	while (runner != nullptr && k>0) {
		k--;
		runner = runner->next;
	}

	if (k > 0) {
		throw std::exception("Pick K thats less than length of list");
	}

	while (runner != nullptr) {
		runner = runner->next;
		head = head->next;
	}

	return *head;
}