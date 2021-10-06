#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float x1, x3, y1, y3, p, s;
    cout << "Enter the coordinates of the first vertex of the rectangle(x1, y1)" << endl;
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second vertex that is opposite to the first vertex of the rectangle(x3,y3)" << endl;
    cin >> x3 >> y3;
    s = abs((y3 - y1) * (x3 - x1));
    p = abs(2 * ((y3 - y1) + (x3 - x1)));
    cout << "The area of the rectangle S = " << s << "\n";
    cout << "The perimeter of the rectangle P = " << p << "\n";
    return 0;
}

