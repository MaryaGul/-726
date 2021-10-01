#include <iostream>
using namespace std;

int main() {
	float a, b, s, d;
	cout << "Enter 1 side of the rectangle" << "\n";
	cin >> a;
	cout << "Enter 2 side of the rectangle" << "\n";
	cin >> b;
	s = a * b;
	d = 2 * (a + b);
	if (a or b <= 0) {
		cout << "The sides of the rectangle must be positive!" << "\n";
	}
	else {
		cout << "The area of the rectangle S = " << s << "\n";
		cout << "The perimeter of the rectangle P = " << d << "\n";
	}
	return 0;
}

