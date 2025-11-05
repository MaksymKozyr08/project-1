#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double dx = x2 - x1;
    double dy = y2 - y1;

    // повернути вектор (dx,dy) на +90° -> (-dy, dx)
    double vx = -dy;
    double vy = dx;

    double x3 = x1 + vx;
    double y3 = y1 + vy;
    double x4 = x2 + vx;
    double y4 = y2 + vy;

    cout << fixed << setprecision(10);
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";
    return 0;
}