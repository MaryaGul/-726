﻿#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float a, b, c, ac, bc, s;
    cout << "Enter the coordinate of point A(one number)" << endl;
    cin >> a;
    cout << "Enter the coordinate of point B(one number)" << endl;
    cin >> b;
    cout << "Enter the coordinate of point C(one number)" << endl;
    cin >> c;
    ac = abs(c - a);
    bc = abs(c - b);
    s = ac + bc;
    cout << "Segment lengths AC= " << ac << endl;
    cout << "Segment lengths BC=" << bc << endl;
    cout << "Sum of segments AC and BC, S=" << s << endl;
    return 0;
}

