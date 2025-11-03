#include <iostream>
#include <vector>

int main() {
    int N;
    if (!(std::cin >> N)) return 0;

    if (N <= 1) return 0;

    // s[x] = сума власних дільників числа x, для 0..N-1
    std::vector<long long> s(N, 0);

    // Для кожного дільника d додаємо його всім кратним m = 2*d, 3*d, ... < N
    for (int d = 1; d <= N/2; ++d) {
        for (int m = 2*d; m < N; m += d) {
            s[m] += d;
        }
    }

    bool found = false;
    for (int a = 2; a < N; ++a) {
        long long b = s[a];
        // b має бути в межах [2, N-1], відмінний від a, та s[b] == a
        if (b > a && b < N) {            // тільки a < b щоб не дублювати (і виключаємо a==b)
            if (s[b] == a) {
                std::cout << a << " " << b << "\n";
                found = true;
            }
        }
    }

    if (!found) {
        // За бажанням можна вивести повідомлення, або нічого не виводити.
        // std::cout << "No amicable pairs less than " << N << "\n";
    }

    return 0;
}
