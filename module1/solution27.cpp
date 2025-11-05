#include <iostream>
#include <iomanip>
int main() {
    double x0, y0;   // координати точки
    double a, b, c;  // коефіцієнти прямої
    
    std::cin >> x0 >> y0 >> a >> b >> c;
    
    double x1 = x0 - 2*a*(a*x0 + b*y0 + c) / (a*a + b*b);
    double y1 = y0 - 2*b*(a*x0 + b*y0 + c) / (a*a + b*b);
    
    std::cout << x1 << " " << y1 << std::endl;
    
    return 0;
}