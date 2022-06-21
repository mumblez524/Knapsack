#include "Knapsack.h"
#include <iostream>

using namespace std;

int main() {
	int limit, num;

	cout << "Weight limit: ";
	cin >> limit;
	cout << "Number of items: ";
	cin >> num;

	Knapsack sack(limit, num);

	cout << "Results.\n\n";
	sack.print();

	system("PAUSE");
	return 0;
}