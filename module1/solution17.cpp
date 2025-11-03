#include <iostream>
#include <cmath>
using namespace std;

// Функція для перевірки, чи можна n представити як a³ - b³
bool canBeRepresentedAsDifferenceOfCubes(long long n) {
    // Випадок 1: n < 0
    // Якщо a, b >= 0 і a >= b, то a³ - b³ >= 0
    // Тому від'ємні числа НЕМОЖЛИВО представити
    if (n < 0) {
        return false;
    }
    
    // Випадок 2: n = 0
    // 0 = a³ - a³ для будь-якого a
    if (n == 0) {
        return true;
    }
    
    // Випадок 3: n > 0
    // Перевіряємо обмеження за модулем 9
    // Куби за модулем 9 можуть бути лише {0, 1, 8}
    // Тому різниця кубів за модулем 9 може бути:
    // 0-0=0, 1-0=1, 8-0=8, 0-1≡8, 1-1=0, 8-1=7, 0-8=1, 1-8≡2, 8-8=0
    // Тобто можливі залишки: {0, 1, 7, 8}
    // Залишки {2, 3, 4, 5, 6} - НЕМОЖЛИВІ
    
    int remainder = n % 9;
    if (remainder == 2 || remainder == 3 || remainder == 4 || 
        remainder == 5 || remainder == 6) {
        return false;
    }
    
    // Для інших випадків перевіряємо перебором
    // Максимальне значення a: a³ <= n, тобто a <= ∛n
    long long maxA = (long long)cbrt(n) + 2; // +2 для точності обчислень
    
    // Перебираємо можливі значення b від 0 до a
    for (long long b = 0; b <= maxA; b++) {
        long long b3 = b * b * b;
        
        // a³ = n + b³
        long long a3 = n + b3;
        
        // Перевіряємо, чи є a3 точним кубом
        long long a = (long long)round(cbrt(a3));
        
        // Перевіряємо точність (через можливі похибки округлення)
        if (a * a * a == a3) {
            return true;
        }
    }
    
    return false;
}

// Функція для знаходження a і b, якщо представлення існує
bool findRepresentation(long long n, long long &a, long long &b) {
    if (n < 0) {
        return false;
    }
    
    if (n == 0) {
        a = 0;
        b = 0;
        return true;
    }
    
    // Перевірка за модулем 9
    int remainder = n % 9;
    if (remainder == 2 || remainder == 3 || remainder == 4 || 
        remainder == 5 || remainder == 6) {
        return false;
    }
    
    long long maxA = (long long)cbrt(n) + 2;
    
    for (long long bVal = 0; bVal <= maxA; bVal++) {
        long long b3 = bVal * bVal * bVal;
        long long a3 = n + b3;
        
        long long aVal = (long long)round(cbrt(a3));
        
        if (aVal * aVal * aVal == a3) {
            a = aVal;
            b = bVal;
            return true;
        }
    }
    
    return false;
}

int main() {
    // Тестування різних чисел
    cout << "Перевірка можливості представлення чисел як різниця кубів a³ - b³\n";
    cout << "================================================================\n\n";
    
    // Тестові випадки
    long long testCases[] = {-5, 0, 1, 2, 7, 8, 26, 27, 63, 64, 91, 100};
    
    for (int i = 0; i < 12; i++) {
        long long n = testCases[i];
        long long a, b;
        
        cout << "n = " << n << ": ";
        
        if (findRepresentation(n, a, b)) {
            cout << "ТАК, " << n << " = " << a << "³ - " << b << "³ = " 
                 << (a*a*a) << " - " << (b*b*b) << endl;
        } else {
            cout << "НІ, неможливо представити" << endl;
        }
    }
    
    cout << "\n\nПояснення неможливих випадків:\n";
    cout << "================================\n";
    cout << "n = 2: 2 ≡ 2 (mod 9), але різниця кубів не може давати залишок 2\n";
    cout << "n = -5: від'ємні числа неможливо представити при a,b >= 0\n";
    
    // Інтерактивна частина
    cout << "\n\nВведіть число для перевірки (або 0 для виходу): ";
    long long n;
    
    while (cin >> n && n != 0) {
        long long a, b;
        
        if (findRepresentation(n, a, b)) {
            cout << "ТАК! " << n << " = " << a << "³ - " << b << "³\n";
            cout << "Перевірка: " << a << "³ - " << b << "³ = " 
                 << (a*a*a) << " - " << (b*b*b) << " = " << (a*a*a - b*b*b) << endl;
        } else {
            cout << "НІ, число " << n << " неможливо представити як різницю кубів\n";
            
            if (n < 0) {
                cout << "Причина: число від'ємне\n";
            } else {
                int remainder = n % 9;
                if (remainder == 2 || remainder == 3 || remainder == 4 || 
                    remainder == 5 || remainder == 6) {
                    cout << "Причина: " << n << " ≡ " << remainder 
                         << " (mod 9), що неможливо для різниці кубів\n";
                }
            }
        }
        
        cout << "\nВведіть наступне число (або 0 для виходу): ";
    }
    
    return 0;
}