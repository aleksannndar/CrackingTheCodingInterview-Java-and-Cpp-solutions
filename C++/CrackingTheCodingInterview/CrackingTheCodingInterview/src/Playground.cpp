#include "../include/ArraysAndStrings.h"

#include <iostream>

int main() {
	int** matrix;

	matrix = new int* [4];
	for (int i = 0; i < 4; i++) {
		matrix[i] = new int[4];
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = i + j - 5;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	solution8a(matrix, 4,4);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < 4; i++) {
		delete[]matrix[i];
	}

	delete[] matrix;


	std::string s1 = "aabcccccaaa";

	std::string s2 = "pale";
	
}