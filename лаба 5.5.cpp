#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float x1, x3, y1, y3, x2, y2, p, s, a, b, c, pp;
    cout << "Enter the coordinates of the 1 vertex of the triangle(x1, y1)" << endl;
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the 2 vertex of the triangle(x2, y2)" << endl;
    cin >> x2 >> y2;
    cout << "Enter the coordinates of the 3 vertex of the triangle(x3, y3)" << endl;
    cin >> x3 >> y3;
    a = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    b = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
    c = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    if ((a + b) > c and (a + c) > b and (c + b) > a) {
        p = a + b + c;
        pp = p / 2;
        s = sqrt(pp * (pp - a) * (pp - b) * (pp - c));
        cout << "The area of the triangle S = " << s << "\n";
        cout << "The perimeter of the triangle P = " << p << "\n";
    }
    else {
        cout << "This triangle does not exist!" << endl;
    }
    return 0;
}

