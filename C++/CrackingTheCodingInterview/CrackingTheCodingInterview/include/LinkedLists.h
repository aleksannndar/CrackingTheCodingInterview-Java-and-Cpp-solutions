#pragma once

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		next = nullptr;
	}
};

void solution1a(Node* head);

void solution1b(Node* head);

Node& solution2a(Node* head, int k);

Node& solution2b(Node* head, int k);