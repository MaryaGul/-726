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
	if (a and b > 0) {
	    cout << "The area of the rectangle S = " << s << "\n";
	    cout << "The perimeter of the rectangle P = " << d << "\n";
		
	}
	else {
		cout << "The sides of the rectangle must be positive!" << "\n";
	}
	return 0;
}
