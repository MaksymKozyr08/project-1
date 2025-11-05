#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double x0, y0;   // координати точки
    double a, b, c;  // коефіцієнти прямої

    std::cin >> x0 >> y0 >> a >> b >> c;

    double x1 = (b*(b*x0 - a*y0) - a*c) / a*a + b*b;
    double y1 = (a*(-b*x0 + a*y0) - b*c) / a*a + b*b;

    std::cout << x1 << " " << y1 << std::endl;

    return 0;
}