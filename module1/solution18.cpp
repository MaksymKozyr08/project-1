#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// Функція для швидкого піднесення до степеня
long long power(long long base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
        // Обмеження для запобігання переповненню
        if (result > 1e15) return result;
    }
    return result;
}

// Перевірка, чи можна n представити як 2^k + 3^m
bool canBeRepresented(long long n, int &k, int &m) {
    // Швидка перевірка: якщо n ділиться на 6, то неможливо
    if (n > 0 && n % 6 == 0) {
        return false;
    }
    
    // Випадок n = 2 (2^1 + 3^0 = 2 + 1 = 3) - НЕ підходить
    // Випадок n = 2 = 2^1 + 0 - але 3^m >= 1
    // Мінімальне значення: 2^0 + 3^0 = 1 + 1 = 2
    
    if (n < 2) {
        return false;
    }
    
    // Обмеження на максимальні степені
    int maxK = (int)(log2(n) + 1);
    int maxM = (int)(log(n) / log(3) + 1);
    
    // Перебір всіх можливих комбінацій k і m
    for (int kVal = 0; kVal <= maxK; kVal++) {
        long long pow2 = power(2, kVal);
        
        if (pow2 > n) break;
        
        for (int mVal = 0; mVal <= maxM; mVal++) {
            long long pow3 = power(3, mVal);
            
            if (pow2 + pow3 > n) break;
            
            if (pow2 + pow3 == n) {
                k = kVal;
                m = mVal;
                return true;
            }
        }
    }
    
    return false;
}

// Знаходження всіх можливих представлень
vector<pair<int, int>> findAllRepresentations(long long n) {
    vector<pair<int, int>> results;
    
    if (n < 2 || n % 6 == 0) {
        return results;
    }
    
    int maxK = (int)(log2(n) + 1);
    int maxM = (int)(log(n) / log(3) + 1);
    
    for (int k = 0; k <= maxK; k++) {
        long long pow2 = power(2, k);
        if (pow2 > n) break;
        
        for (int m = 0; m <= maxM; m++) {
            long long pow3 = power(3, m);
            
            if (pow2 + pow3 > n) break;
            
            if (pow2 + pow3 == n) {
                results.push_back({k, m});
            }
        }
    }
    
    return results;
}

int main() {
    cout << "Перевірка можливості представлення чисел у вигляді n = 2^k + 3^m\n";
    cout << "================================================================\n\n";
    
    // Перевірка перших 50 чисел
    cout << "Аналіз чисел від 1 до 50:\n";
    cout << "-------------------------\n";
    
    vector<long long> impossible;
    
    for (long long n = 1; n <= 50; n++) {
        int k, m;
        if (canBeRepresented(n, k, m)) {
            cout << n << " = 2^" << k << " + 3^" << m 
                 << " = " << power(2, k) << " + " << power(3, m) << " ✓\n";
        } else {
            cout << n << " - НЕМОЖЛИВО ✗\n";
            impossible.push_back(n);
        }
    }
    
    cout << "\n\nНеможливі числа (1-50): ";
    for (long long num : impossible) {
        cout << num << " ";
    }
    cout << endl;
    
    // Перевірка гіпотези про кратність 6
    cout << "\n\nПеревірка гіпотези про кратність 6:\n";
    cout << "====================================\n";
    bool hypothesis = true;
    for (long long num : impossible) {
        if (num % 6 != 0 && num != 1) {
            hypothesis = false;
            cout << "Виняток: " << num << " не ділиться на 6, але неможливо представити!\n";
        }
    }
    
    if (hypothesis) {
        cout << "✓ Всі неможливі числа (крім 1) діляться на 6!\n";
    }
    
    // Демонстрація для кількох чисел, кратних 6
    cout << "\n\nПеревірка чисел, кратних 6:\n";
    cout << "============================\n";
    long long multiples[] = {6, 12, 18, 24, 30, 36, 42, 48, 54, 60};
    
    for (long long n : multiples) {
        int k, m;
        cout << n << ": ";
        if (canBeRepresented(n, k, m)) {
            cout << "МОЖЛИВО (несподіванка!)\n";
        } else {
            cout << "неможливо (як і очікувалось)\n";
        }
    }
    
    // Інтерактивна частина
    cout << "\n\nВведіть число для перевірки (або 0 для виходу): ";
    long long n;
    
    while (cin >> n && n != 0) {
        auto representations = findAllRepresentations(n);
        
        if (representations.empty()) {
            cout << "НІ, число " << n << " неможливо представити як 2^k + 3^m\n";
            
            if (n % 6 == 0) {
                cout << "Причина: " << n << " ділиться на 6\n";
                cout << "Пояснення: 2^k + 3^m (mod 6) ∈ {1,2,3,4,5}, але не може бути 0\n";
            } else if (n == 1) {
                cout << "Причина: мінімальне значення 2^0 + 3^0 = 2\n";
            }
        } else {
            cout << "ТАК! Знайдено " << representations.size() << " представлення(ь):\n";
            for (auto [k, m] : representations) {
                cout << "  " << n << " = 2^" << k << " + 3^" << m 
                     << " = " << power(2, k) << " + " << power(3, m) << endl;
            }
        }
        
        cout << "\nВведіть наступне число (або 0 для виходу): ";
    }
    
    return 0;
}