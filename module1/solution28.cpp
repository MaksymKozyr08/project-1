#include <iostream>
#include <iomanip>
int main() {
    double x0, y0, a, b;
    std::cin >> x0 >> y0 >> a >> b;

    double c = -b * x0 + a * y0;
    double k = -b / c;
    double m =  a / c;

    std::cout << "Perpendicular line: " << k << "x + " << m << "y = 1" << std::endl;

    return 0;
}