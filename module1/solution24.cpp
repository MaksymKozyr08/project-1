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
    double cos60 = 0.5;
    double sin60 = std::sqrt(3) / 2;
    
    // Обчислюємо координати третьої вершини (поворот на +60°)
    double x3 = x1 + dx * cos60 - dy * sin60;
    double y3 = y1 + dx * sin60 + dy * cos60;
    std::cout << x3 << " " << y3 << std::endl;
    
    return 0;
}