#include <iostream>
using namespace std;

int main() {
    float a, b, c, ac, bc, p;
    cout << "Enter the coordinate of point A(one number)" << endl;
    cin >> a;
    cout << "Enter the coordinate of point B(one number)" << endl;
    cin >> b;
    cout << "Enter the coordinate of point C, which is located between points A and B(A<C<B)" << endl;
    cin >> c;
    if (a < c and c < b) {
        ac = c - a;
        bc = b - c;
        p = ac * bc;
        cout << "Product of line segments AC*BC=" << p << endl;
    }
    else {
        cout << "Coordinate of point c must be greater than coordinate A and less than coordinate B! " << endl;
    }
    return 0;
}
