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

    // одне з рішень (перший варіант)
    double cx = (x1 + x2 - dy) / 2.0;
    double cy = (y1 + y2 + dx) / 2.0;

    cout.setf(std::ios::fixed); cout << setprecision(10);
    cout << cx << " " << cy << "\n";
    return 0;
}