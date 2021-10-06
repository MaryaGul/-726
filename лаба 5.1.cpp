
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float x1, x2, y1, y2, r;
    cout << "Enter the coordinates of 1 point (x1, y1)" << endl;
    cin >> x1 >> y1;
    cout << "Enter the coordinates of 2 point (x2, y2)" << endl;
    cin >> x2 >> y2;
    r = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    cout << "The distance between two points R= " << r << endl;

    return 0;
}
