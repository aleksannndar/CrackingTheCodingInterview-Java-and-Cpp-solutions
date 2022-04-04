#include "../include/ArraysAndStrings.h"
#include<math.h>

//space O(1), time O(n)
bool solution1a(std::string& const input) {
	if (input.size() == 0)
		return false;

	bool charOccured[128];

	for (int i = 0; i < sizeof(charOccured) / sizeof(bool); i++) {
		charOccured[i] = false;
	}

	for (int i = 0; i < input.size(); i++) {
		if (charOccured[input.at(i)]) {
			return false;
		}
		else {
			charOccured[input.at(i)] = true;
		}
	}

	return true;
}

//space O(1), time O(n^2)
bool solution1b(std::string& const input) {
	if (input.size() == 0)
		return false;

	for (int i = 0; i < input.size() - 1; i++) {
		for (int j = i + 1; j < input.size(); j++) {
			if (input.at(i) == input.at(j))
				return false;
		}
	}
	return true;
}

//space O(1), time O(n)
bool solution2a(std::string& const s1, std::string& const s2) {
	if (s1.size() == 0 || s2.size() == 0 || s2.size() != s1.size())
		return false;

	int charOccurances[128];

	for (int i = 0; i < sizeof(charOccurances) / sizeof(int); i++) {
		charOccurances[i] = 0;
	}

	for (int i = 0; i < s1.size(); i++) {
		charOccurances[s1.at(i)]++;
		charOccurances[s2.at(i)]--;
	}

	for (int i = 0; i < sizeof(charOccurances) / sizeof(int); i++) {
		if (charOccurances[i] != 0)
			return false;
	}

	return true;
}

//space O(1), time O(n)
void solution3a(std::string& input, int trueLength) {
	if (input.size() == 0)
		throw "Invalid input exception";

	int length = input.size() - 1;
	trueLength -= 1;

	while (trueLength >= 0) {
		if (input[trueLength] == ' ') {
			input[length] = '0';
			length--;
			input[length] = '2';
			length--;
			input[length] = '%';
			length--;
		}
		else {
			input[length] = input[trueLength];
			length--;
		}
		trueLength--;
	}
}

//space O(1), time O(n)
bool solution4a(std::string& const input) {
	if (input.size() == 0)
		return false;

	int charOccurances[128];

	for (int i = 0; i < sizeof(charOccurances) / sizeof(int); i++) {
		charOccurances[i] = 0;
	}

	for (int i = 0; i < input.size(); i++) {
		if (input[i] != ' ') {
			char c = tolower(input[i]);
			charOccurances[c]++;
		}
	}

	int oddCounter = 0;
	
	for (int i = 0; i < sizeof(charOccurances) / sizeof(int); i++) {
		if (charOccurances[i] % 2 == 1)
			oddCounter++;
	}

	return oddCounter > 1 ? false : true;

}

//space O(1), time O(n)
bool solution5a(std::string& const s1, std::string& const s2) {
	if (std::abs((int) (s1.size() - s2.size())) > 1)
		return false;

	bool changed = false;

	int l1 = 0;
	int l2 = 0;

	while (l1 < s1.size() && l2 < s2.size()) {
		if (s1[l1] != s2[l2]) {
			if (changed) {
				return false;
			}
			else {
				if (s1.size() != s2.size()) {
					if (s1.size() > s2.size()) {
						l1++;
					}
					if (s2.size() > s1.size()) {
						l2++;
					}
				}
				else {
					l1++;
					l2++;
				}
				changed = true;
			}
		}
		else {
			l1++;
			l2++;
		}
	}

	return true;
}

//space O(1), time O(n)
std::string solution6a(std::string& const input) {
	if (input.size() < 2)
		return input;

	std::string output = "";

	int counter = 1;
	for (int i = 1; i < input.size(); i++) {
		if (input[i - 1] != input[i]) {
			output += input[i - 1];
			output += std::to_string(counter);
			counter = 1;
		}
		else {
			counter++;
		}
	}

	output += input[input.size() - 1];
	output += std::to_string(counter);

	return output.size() < input.size() ? output : input;
}

//space O(1), time O(n^2)
void solution7a(int** matrix, int n) {
	for (int i = 0; i < n / 2; i++) {
		int last = n - 1 - i;
		for (int j = i; j < last; j++) {
			int top = matrix[i][j];

			//left -> top
			matrix[i][j] = matrix[n - 1 - j][i];

			//bot -> left
			matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];

			//right -> bot
			matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];

			//top -> right
			matrix[j][n - 1 - i] = top;
		}
	}
}

//space O(1), time O(n^2)
void solution8a(int** matrix, int m, int n) {
	bool columnZeros = false;
	bool rowZeros = false;

	for (int i = 0; i < m; i++) {
		if (matrix[i][0] == 0) {
			columnZeros = true;
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		if (matrix[0][i] == 0) {
			rowZeros = true;
			break;
		}
	}

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}

	if (columnZeros) {
		for (int i = 0; i < n; i++) {
			matrix[0][i] = 0;
		}
	}

	if (rowZeros) {
		for (int i = 0; i < m; i++) {
			matrix[i][0] = 0;
		}
	}
}

//depends on isSubstring
//bool solution9a(std::string s1, std::string s2) {
//	return isSubstring(s2 + s2, s1);
//}