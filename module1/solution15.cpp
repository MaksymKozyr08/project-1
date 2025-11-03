#include <iostream>
#include <iomanip>

int main() {
    double K;
    std::cin >> K;

    double sum = 0.0;
    int n = 0;

    while (sum <= K) {
        n++;
        sum += 1.0 / n;
    }

    std::cout << n << std::endl;
    return 0;
}
