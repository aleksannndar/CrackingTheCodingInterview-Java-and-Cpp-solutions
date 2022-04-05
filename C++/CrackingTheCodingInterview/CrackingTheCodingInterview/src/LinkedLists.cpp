#include "../include/LinkedLists.h"

#include <unordered_set>
#include <memory>
#include <stack>

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
//space O(1), time O(n)
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
//space O(1), time O(n)
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

//space O(1), time O(1)
void solution3a(Node* middle) {
	if (middle->next == nullptr)
		throw std::exception("This is last node!");

	middle->data = middle->next->data;
	middle->next = middle->next->next;
}

//space O(1), time O(n)
Node& solution4a(Node* head, int k) {
	Node* smaller = nullptr;
	Node* greater = nullptr;
	Node* smallerRunner = nullptr;

	while (head != nullptr) {
		Node* next = head->next;
		if (head->data < k) {
			if (smaller == nullptr) {
				smaller = head;
				smallerRunner = smaller;
			}
			else {
				head->next = smaller;
				smaller = head;
			}
		}
		else {
			head->next = greater;
			greater = head;
		}
		head = next;
	}

	if (smallerRunner != nullptr) {
		smallerRunner->next = greater;
	}

	return smaller == nullptr ? *greater : *smaller;
}

//space O(n), time O(n)
Node& solution5a(Node* l1, Node* l2) {
	if (l1 == nullptr && l2 == nullptr) {
		throw std::exception("Both lists are empty");
	}

	if (l1 == nullptr)
		return *l2;

	if (l2 == nullptr)
		return *l1;

	Node* sum = nullptr;
	Node* runner = sum;
	int carry = 0;
	int value = 0;
	while (l1 != nullptr && l2 != nullptr) {
		value = l1->data + l2->data + carry;
		carry = value / 10;
		Node* tmp = new Node(value % 10);
		if (sum == nullptr) {
			sum = tmp;
			runner = sum;
		}
		else {
			runner->next = tmp;
			runner = runner->next;
		}
		l1 = l1->next;
		l2 = l2->next;
	}

	Node* leftOver = l1 == nullptr ? l2 : l1;
	while (leftOver != nullptr) {
		value = leftOver->data + carry;
		carry = value / 10;
		runner->next = new Node(value % 10);
		runner = runner->next;

		leftOver = leftOver->next;
	}

	if (carry > 0)
		runner->next = new Node(carry);

	return *sum;
}

//space O(1), time O(n)
bool solution6a(Node* head) {
	if (head == nullptr) {
		throw std::exception("List is empty");
	}

	std::stack<int> stackData = std::stack<int>();
	Node* fastRunner = head;

	while (fastRunner != nullptr && fastRunner->next != nullptr) {
		stackData.push(head->data);
		head = head->next;
		fastRunner = fastRunner->next->next;
	}

	if (fastRunner != nullptr)
		head = head->next;

	while (head != nullptr) {
		if (head->data != stackData.top())
			return false;
		head = head->next;
		stackData.pop();
	}

	return true;
}

//space O(1), time O(n)
Node* solution7a(Node* l1, Node* l2) {
	if (l1 == nullptr || l2 == nullptr)
		return nullptr;

	Node* tmp1 = l1;
	Node* tmp2 = l2;

	int counter1 = 0;
	int counter2 = 0;

	while (tmp1 != nullptr) {
		counter1++;
		tmp1 = tmp1->next;
	}

	while (tmp2 != nullptr) {
		counter2++;
		tmp2 = tmp2->next;
	}

	tmp1 = counter1 > counter2 ? l1 : l2;

	tmp2 = counter1 > counter2 ? l2 : l1;

	for (int i = 0; i < std::abs(counter1 - counter2); i++) {
		tmp1 = tmp1->next;
	}

	while (tmp1 != nullptr && tmp2 != nullptr) {
		if (tmp1 == tmp2)
			return tmp1;
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	
	return nullptr;
}

//space O(1), time O(n)
Node* solution8a(Node* head) {
	if (head == nullptr)
		return nullptr;

	Node* fast = head;
	Node* slow = head;

	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
			break;
	}

	if (fast == nullptr || fast->next == nullptr)
		return nullptr;

	slow = head;
	while (slow != head) {
		slow = slow->next;
		head = head->next;
	}

	return slow;
}