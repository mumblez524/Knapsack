#include "Knapsack.h"
#include <iostream>

using namespace std;

Knapsack::Knapsack(int l, int n) {
	limit = l;
	num = n;
	items = new string[n];
	weights = new int[n];
	values = new int[n];

	buildLists();

	matrix = new int* [n + 1];
	for (int i = 0; i < n + 1; i++) {
		matrix[i] = new int[l + 1];
	}

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < l + 1; j++)
			matrix[i][j] = 0;
	}
}
void Knapsack::buildLists() {
	for (int i = 0; i < num; i++) {
		cout << "Item " << i + 1 << ":\n";
		cout << "     Name: ";
		cin >> items[i];
		cout << "     Weight: ";
		cin >> weights[i];
		cout << "     Value: ";
		cin >> values[i];
	}
	cout << endl;
}

void Knapsack::print() {
	int i, w;

	for (i = 0; i <= num; i++) {
		for (w = 0; w <= limit; w++) {
			if (i == 0 || w == 0)
				matrix[i][w] = 0;
			else if (weights[i - 1] <= w)
				matrix[i][w] = max(values[i - 1] +
					matrix[i - 1][w - weights[i - 1]], matrix[i - 1][w]);
			else
				matrix[i][w] = matrix[i - 1][w];
		}
	}
	int res = matrix[num][limit],
		tweight = 0;

	w = limit;
	for (i = num; i > 0 && res > 0; i--) {
		if (res == matrix[i - 1][w])
			continue;
		else {
			cout << "Name: " << items[i - 1] << "\n     Weight: " << weights[i - 1]
				<< "\n     Value: " << values[i - 1] << endl;
			res = res - values[i - 1];
			w = w - weights[i - 1];
			tweight += weights[i - 1];
		}
	}
	cout << endl;
	cout << "Total Weight: " << tweight << endl;
	cout << "Total Value: " << matrix[num][limit] << endl;
}
int Knapsack::max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

Knapsack::~Knapsack() {
	delete[]items;
	delete[]weights;
	delete[]values;

	for (int i = 0; i < num + 1; i++) {
		delete[]matrix[i];
	}
	delete[]matrix;
}