#ifndef KNAPSACK_H
#define KNAPSACK_H
#include <string>

using namespace std;

class Knapsack {
private:
	int limit;
	int num;
	string* items;
	int* weights;
	int* values;
	int** matrix;
public:
	Knapsack(int, int);
	void buildLists();
	void print();
	int max(int, int);

	~Knapsack();
};

#endif