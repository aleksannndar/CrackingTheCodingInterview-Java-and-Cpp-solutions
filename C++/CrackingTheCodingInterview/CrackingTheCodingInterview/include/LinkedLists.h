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

void solution3a(Node* middle);

Node& solution4a(Node* head, int k);

Node& solution5a(Node* l1, Node* l2);

bool solution6a(Node* head);

Node* solution7a(Node* l1, Node* l2);

