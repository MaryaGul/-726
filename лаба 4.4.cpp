#include <iostream>
using namespace std;

int main() {
	float a, b, s, r, p, ch;
	cout << "Please enter a nonzero 1 number" << "\n";
	cin >> a;
	cout << "Please enter a nonzero 2 number" << "\n";
	cin >> b;
	s = a * a + b * b;
	r = a * a - b * b;
	p = (a * a) * (b * b);
	ch = (a * a) / (b * b);
	if (a and b != 0) {
		cout << "Sum of squares of numbers s = " << s << "\n";
		cout << "Difference of squares of numbersr = " << r << "\n";
		cout << "Product of squares of numbersp = " << p << "\n";
		cout << "Quotient of squares of numbersch = " << ch << "\n";
	}
	else {
		cout << "The number must be nonzero!" << "\n";
	}
	return 0;
}
