#include <memory>
#include <iostream>
#include <vector>

template<typename T>
class NodeSQ {
public:
	T data;
	NodeSQ<T>* next;

	NodeSQ(T data) {
		this->data = data;
		this->next = nullptr;
	}
};

template<typename T>
class MyStack {
public:
	NodeSQ<T>* top;

	MyStack() {
		top = nullptr;
	}

	~MyStack() {
		while (top != nullptr) {
			NodeSQ<T>* next = top->next;
			delete top;
			top = next;
		}
		std::cout << "Stack is destroyed" << std::endl;
	}

	void push(T data) {
		if (top == nullptr) {
			top = new NodeSQ<T>(data);
		}
		else {
			NodeSQ<T>* tmp = new NodeSQ<T>(data);
			tmp->next = top;
			top = tmp;
		}
	}

	T pop() {
		if (isEmpty()) {
			throw std::exception("Stack is empty");
		}
		else {
			NodeSQ<T>* rm = top;
			top = top->next;
			return rm->data;
		}
	}

	T peek() {
		if (isEmpty()) {
			throw std::exception("Stack is empty");
		}
		else {
			return top->data;
		}
	}

	bool isEmpty() {
		return top == nullptr ? true : false;
	}
};

template<typename T>
class MyQueue {
public:
	NodeSQ<T>* first;
	NodeSQ<T>* last;

	MyQueue() {
		this->first = nullptr;
		this->last = nullptr;
	}

	~MyQueue() {
		while (first != nullptr) {
			NodeSQ<T>* next = first->next;
			delete first;
			first = next;
		}
		last = nullptr;
		std::cout << "Queue destroyed!" << std::endl;
	}
	
	void push(T data) {
		if (first == nullptr) {
			first = new NodeSQ<T>(data);
			last = first;
		}
		else {
			last->next = new NodeSQ<T>(data);
			last = last->next;
		}
	}

	T peek() {
		if (isEmpty()) {
			throw std::exception("Queue is empty");
		}
		else {
			return first->data;
		}
	}

	T remove() {
		if (isEmpty()) {
			throw std::exception("Queue is empty");
		}
		else {
			NodeSQ<T>* rm = first;
			first = first->next;
			return rm->data;
		}
	}

	bool isEmpty() {
		return first == nullptr ? true : false;
	}

};


class StackMin : public MyStack<int> {
public:
	MyStack<int> mins = MyStack<int>();

	void push(int data) {
		if (isEmpty()) {
			MyStack::push(data);
			mins.push(data);
		}
		else {
			if (data <= mins.peek()) {
				mins.push(data);
			}
			MyStack::push(data);
		}
	}

	int pop() {
		int rm = MyStack::pop();
		if (rm == mins.peek())
			mins.pop();
		return rm;
	}

	int getMin() {
		return mins.peek();
	}
};

