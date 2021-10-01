#include <iostream>
using namespace std;

int main() {
	float L, d, P = 3.14;
	cout << "Enter the daimetr of the circle" << "\n";
	cin >> d;
	L = P * d;
	if (d <= 0) {
		cout << "The daimetr of the circle must be positive!" << "\n";
	}
	else {
		cout << "The circumference L = " << L << "\n";
	}
	return 0;
}
