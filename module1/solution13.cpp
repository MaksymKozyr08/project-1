#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double eps;
    std::cin >> eps;

    double x_prev = 0.0;
    double x_next = std::sqrt(7.0 + x_prev);

    while (std::fabs(x_next - x_prev) > eps) {
        x_prev = x_next;
        x_next = std::sqrt(7.0 + x_prev);
    }

    std::cout << std::fixed << std::setprecision(10) << x_next << std::endl;

    return 0;
}
