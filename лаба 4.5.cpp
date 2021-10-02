#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float a,  b, s, r, p, ch;
	cout << "Please enter a nonzero 1 number" << "\n";
	cin >> a;
	cout << "Please enter a nonzero 2 number" << "\n";
	cin >> b;
	if (a and b != 0) {
		s = fabs(a)  + fabs(b) ;
		r = fabs(a) - fabs(b);
		p = fabs(a) * fabs(b);
		ch = fabs(a) / fabs(b);
		cout << "Sum of modules of numbers s = " << s << "\n";
		cout << "Difference of modules of numbersr = " << r << "\n";
		cout << "Product of modules of numbersp = " << p << "\n";
		cout << "Quotient of modules of numbersch = " << ch << "\n";
		
	}
	else {
		cout << "The number must be nonzero!" << "\n";
	}
	return 0;
}
