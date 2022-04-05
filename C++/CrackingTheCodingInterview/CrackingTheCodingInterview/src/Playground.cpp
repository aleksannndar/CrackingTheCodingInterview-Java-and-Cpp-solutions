#include "../include/LinkedLists.h"

#include <iostream>

int main() {
	//int** matrix;

	//matrix = new int* [4];
	//for (int i = 0; i < 4; i++) {
	//	matrix[i] = new int[4];
	//}

	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		matrix[i][j] = i + j - 5;
	//	}
	//}

	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		std::cout << matrix[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << std::endl;
	//std::cout << std::endl;
	//std::cout << std::endl;

	//solution8a(matrix, 4,4);

	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		std::cout << matrix[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//for (int i = 0; i < 4; i++) {
	//	delete[]matrix[i];
	//}

	//delete[] matrix;


	//std::string s1 = "aabcccccaaa";

	//std::string s2 = "pale";

	Node n1 = Node(1);
	Node n2 = Node(5);
	Node n3 = Node(3);
	Node n4 = Node(1);
	Node n5 = Node(2);
	Node n6 = Node(3);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;

	try {
		Node* result = &solution2b(&n1, 15);
		std::cout << "Data: " << result->data << std::endl;
	}
	catch (std::exception e) {
		std::cout << "Exception occured! And it says: " << e.what() << std::endl;
	}
	//Node* head = &n1;

	//while (head != nullptr) {
	//	std::cout << "Data: " << head->data << std::endl;
	//	head = head->next;
	//}
 	
}