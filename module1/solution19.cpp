#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// Функція для перевірки, чи можна число представити як 13k + 7m
bool canBeRepresented(int n, int &k, int &m) {
    // Перебираємо всі можливі значення k
    // Максимальне k: 13k <= n, тобто k <= n/13
    for (int kVal = 0; kVal * 13 <= n; kVal++) {
        int remainder = n - 13 * kVal;
        
        // Перевіряємо, чи ділиться залишок на 7
        if (remainder >= 0 && remainder % 7 == 0) {
            k = kVal;
            m = remainder / 7;
            return true;
        }
    }
    
    return false;
}

// Знаходження всіх можливих представлень числа n
vector<pair<int, int>> findAllRepresentations(int n) {
    vector<pair<int, int>> results;
    
    for (int k = 0; k * 13 <= n; k++) {
        int remainder = n - 13 * k;
        
        if (remainder >= 0 && remainder % 7 == 0) {
            int m = remainder / 7;
            results.push_back({k, m});
        }
    }
    
    return results;
}

// Знаходження всіх чисел < n, які можна представити
vector<int> findRepresentableNumbers(int n) {
    vector<int> result;
    
    for (int i = 0; i < n; i++) {
        int k, m;
        if (canBeRepresented(i, k, m)) {
            result.push_back(i);
        }
    }
    
    return result;
}

// Знаходження всіх чисел < n, які НЕ можна представити
vector<int> findNonRepresentableNumbers(int n) {
    vector<int> result;
    
    for (int i = 0; i < n; i++) {
        int k, m;
        if (!canBeRepresented(i, k, m)) {
            result.push_back(i);
        }
    }
    
    return result;
}

// Виведення чисел у форматованому вигляді (по 10 в рядку)
void printNumbers(const vector<int>& numbers, int perLine = 10) {
    for (size_t i = 0; i < numbers.size(); i++) {
        cout << setw(4) << numbers[i];
        if ((i + 1) % perLine == 0) {
            cout << endl;
        }
    }
    if (numbers.size() % perLine != 0) {
        cout << endl;
    }
}

int main() {
    cout << "Знаходження чисел, які можна представити як n = 13k + 7m\n";
    cout << "=========================================================\n\n";
    
    // Теоретична інформація
    cout << "Теорія:\n";
    cout << "-------\n";
    cout << "НСД(13, 7) = 1 (взаємно прості)\n";
    cout << "Число Фробеніуса: g(13,7) = 13×7 - 13 - 7 = 71\n";
    cout << "Висновок: всі числа >= 72 можна представити як 13k + 7m\n\n";
    
    // Аналіз чисел від 0 до 100
    int limit = 100;
    
    cout << "Аналіз чисел від 0 до " << limit << ":\n";
    cout << "====================================\n\n";
    
    // Знаходимо числа, які можна представити
    vector<int> representable = findRepresentableNumbers(limit);
    vector<int> nonRepresentable = findNonRepresentableNumbers(limit);
    
    cout << "Числа, які МОЖНА представити (" << representable.size() << " чисел):\n";
    printNumbers(representable, 15);
    
    cout << "\n\nЧисла, які НЕМОЖЛИВО представити (" << nonRepresentable.size() << " чисел):\n";
    printNumbers(nonRepresentable, 15);
    
    // Перевірка теореми Фробеніуса
    cout << "\n\nПеревірка теореми Фробеніуса:\n";
    cout << "==============================\n";
    cout << "Найбільше неможливе число: ";
    if (!nonRepresentable.empty()) {
        cout << nonRepresentable.back() << endl;
        cout << "Теоретичне значення (число Фробеніуса): 71\n";
        
        if (nonRepresentable.back() == 71) {
            cout << "✓ Теорія підтверджується!\n";
        }
    }
    
    // Детальний аналіз кількох чисел
    cout << "\n\nДетальний аналіз деяких чисел:\n";
    cout << "===============================\n";
    
    int examples[] = {0, 7, 13, 20, 50, 71, 72, 100};
    
    for (int num : examples) {
        cout << "\nn = " << num << ":\n";
        auto reps = findAllRepresentations(num);
        
        if (reps.empty()) {
            cout << "  НЕМОЖЛИВО представити\n";
        } else {
            cout << "  Знайдено " << reps.size() << " спосіб(ів):\n";
            for (auto [k, m] : reps) {
                cout << "  " << num << " = 13×" << k << " + 7×" << m 
                     << " = " << (13*k) << " + " << (7*m) << endl;
            }
        }
    }
    
    // Інтерактивна частина
    cout << "\n\n" << string(60, '=') << endl;
    cout << "Інтерактивний режим\n";
    cout << string(60, '=') << endl;
    
    while (true) {
        cout << "\nВиберіть опцію:\n";
        cout << "1 - Вивести всі числа < n, які можна представити\n";
        cout << "2 - Перевірити конкретне число\n";
        cout << "3 - Знайти всі способи представлення числа\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        
        int choice;
        cin >> choice;
        
        if (choice == 0) break;
        
        if (choice == 1) {
            int n;
            cout << "Введіть n: ";
            cin >> n;
            
            vector<int> nums = findRepresentableNumbers(n);
            cout << "\nЧисла < " << n << ", які можна представити (" 
                 << nums.size() << " чисел):\n";
            printNumbers(nums, 15);
            
            vector<int> nonNums = findNonRepresentableNumbers(n);
            cout << "\nЧисла < " << n << ", які НЕМОЖЛИВО представити (" 
                 << nonNums.size() << " чисел):\n";
            printNumbers(nonNums, 15);
            
        } else if (choice == 2) {
            int num;
            cout << "Введіть число: ";
            cin >> num;
            
            int k, m;
            if (canBeRepresented(num, k, m)) {
                cout << "ТАК, " << num << " = 13×" << k << " + 7×" << m << endl;
                cout << "Перевірка: 13×" << k << " + 7×" << m 
                     << " = " << (13*k) << " + " << (7*m) << " = " << (13*k + 7*m) << endl;
            } else {
                cout << "НІ, " << num << " неможливо представити як 13k + 7m\n";
            }
            
        } else if (choice == 3) {
            int num;
            cout << "Введіть число: ";
            cin >> num;
            
            auto reps = findAllRepresentations(num);
            
            if (reps.empty()) {
                cout << num << " - неможливо представити\n";
            } else {
                cout << "Знайдено " << reps.size() << " спосіб(ів) представлення " << num << ":\n";
                for (size_t i = 0; i < reps.size(); i++) {
                    auto [k, m] = reps[i];
                    cout << (i+1) << ". " << num << " = 13×" << k << " + 7×" << m 
                         << " = " << (13*k) << " + " << (7*m) << endl;
                }
            }
        }
    }
    
    cout << "\nДякую за використання програми!\n";
    
    return 0;
}