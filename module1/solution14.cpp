#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double eps;
    std::cin >> eps; // читаємо epsilon (без додаткових перевірок)

    double x_prev = 1.0;
    double x_next = 1.0 + 1.0 / x_prev;

    // Ітерації фікс-пойнту: x_{n+1} = 1 + 1/x_n
    while (std::fabs(x_next - x_prev) > eps) {
        x_prev = x_next;
        x_next = 1.0 + 1.0 / x_prev;
    }

    std::cout << std::fixed << std::setprecision(12) << x_next << "\n";
    return 0;
}
