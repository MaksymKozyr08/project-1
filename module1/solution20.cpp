#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

// Функція для перевірки, чи є число виду 2^k * 3^m
bool isHammingNumber(long long n, int &k, int &m) {
    if (n <= 0) return false;
    
    k = 0;
    m = 0;
    
    // Ділимо на 2 доки можливо
    while (n % 2 == 0) {
        n /= 2;
        k++;
    }
    
    // Ділимо на 3 доки можливо
    while (n % 3 == 0) {
        n /= 3;
        m++;
    }
    
    // Якщо залишилось 1, то число має вигляд 2^k * 3^m
    return n == 1;
}

// Генерація всіх чисел Хеммінга < n (ефективний метод)
vector<long long> generateHammingNumbers(long long limit) {
    set<long long> hammingSet;
    hammingSet.insert(1);
    
    vector<long long> result;
    
    // Генеруємо числа, множачи на 2 і 3
    for (long long num : hammingSet) {
        if (num >= limit) break;
        
        result.push_back(num);
        
        // Додаємо num * 2, якщо воно менше ліміту
        if (num * 2 < limit) {
            hammingSet.insert(num * 2);
        }
        
        // Додаємо num * 3, якщо воно менше ліміту
        if (num * 3 < limit) {
            hammingSet.insert(num * 3);
        }
    }
    
    sort(result.begin(), result.end());
    return result;
}

// Альтернативний метод: перебір всіх k і m
vector<long long> generateHammingNumbersBrute(long long limit) {
    set<long long> hammingSet;
    
    // Максимальні значення k і m
    int maxK = (int)(log2(limit)) + 1;
    int maxM = (int)(log(limit) / log(3)) + 1;
    
    // Генеруємо всі можливі комбінації 2^k * 3^m
    for (int k = 0; k <= maxK; k++) {
        long long pow2 = 1LL << k; // 2^k
        
        if (pow2 >= limit) break;
        
        for (int m = 0; m <= maxM; m++) {
            long long pow3 = 1;
            for (int i = 0; i < m; i++) {
                pow3 *= 3;
                if (pow3 > limit / pow2) break; // Запобігаємо переповненню
            }
            
            long long num = pow2 * pow3;
            
            if (num < limit) {
                hammingSet.insert(num);
            } else {
                break;
            }
        }
    }
    
    vector<long long> result(hammingSet.begin(), hammingSet.end());
    return result;
}

// Функція для обчислення 2^k * 3^m
long long computeHamming(int k, int m) {
    long long result = 1;
    
    // Обчислюємо 2^k
    for (int i = 0; i < k; i++) {
        result *= 2;
        if (result > 1e15) return -1; // Переповнення
    }
    
    // Множимо на 3^m
    for (int i = 0; i < m; i++) {
        result *= 3;
        if (result > 1e15) return -1; // Переповнення
    }
    
    return result;
}

// Виведення чисел у форматованому вигляді
void printNumbers(const vector<long long>& numbers, int perLine = 10) {
    for (size_t i = 0; i < numbers.size(); i++) {
        cout << setw(8) << numbers[i];
        if ((i + 1) % perLine == 0) {
            cout << endl;
        }
    }
    if (numbers.size() % perLine != 0) {
        cout << endl;
    }
}

// Виведення чисел з представленням
void printNumbersWithRepresentation(const vector<long long>& numbers, int count = 20) {
    int displayed = 0;
    for (long long num : numbers) {
        if (displayed >= count) break;
        
        int k, m;
        if (isHammingNumber(num, k, m)) {
            cout << setw(8) << num << " = 2^" << k << " × 3^" << m << endl;
            displayed++;
        }
    }
}

int main() {
    cout << "Знаходження чисел виду n = 2^k × 3^m (числа Хеммінга)\n";
    cout << "======================================================\n\n";
    
    // Теоретична інформація
    cout << "Теорія:\n";
    cout << "-------\n";
    cout << "Числа виду 2^k × 3^m називаються регулярними числами Хеммінга.\n";
    cout << "Це числа, які мають у розкладі на прості множники лише 2 і 3.\n";
    cout << "Приклади: 1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 27, ...\n\n";
    
    // Генеруємо числа Хеммінга до 1000
    long long limit = 1000;
    
    cout << "Генерація чисел Хеммінга < " << limit << ":\n";
    cout << string(50, '=') << endl;
    
    vector<long long> hamming = generateHammingNumbersBrute(limit);
    
    cout << "\nЗнайдено " << hamming.size() << " чисел Хеммінга < " << limit << "\n\n";
    
    cout << "Перші 30 чисел з представленням:\n";
    cout << string(50, '-') << endl;
    printNumbersWithRepresentation(hamming, 30);
    
    cout << "\nВсі числа Хеммінга < " << limit << ":\n";
    cout << string(50, '-') << endl;
    printNumbers(hamming, 12);
    
    // Статистика
    cout << "\n\nСтатистика:\n";
    cout << string(50, '=') << endl;
    cout << "Всього чисел < " << limit << ": " << limit << endl;
    cout << "Чисел Хеммінга: " << hamming.size() << endl;
    cout << "Відсоток: " << fixed << setprecision(2) 
         << (100.0 * hamming.size() / limit) << "%\n";
    cout << "Не є числами Хеммінга: " << (limit - hamming.size()) << endl;
    
    // Приклади чисел, які НЕ є числами Хеммінга
    cout << "\n\nПриклади чисел, які НЕ є числами Хеммінга:\n";
    cout << string(50, '-') << endl;
    
    set<long long> hammingSet(hamming.begin(), hamming.end());
    vector<long long> nonHamming;
    
    for (long long i = 1; i < min(limit, 100LL); i++) {
        if (hammingSet.find(i) == hammingSet.end()) {
            nonHamming.push_back(i);
        }
    }
    
    cout << "Перші 30 не-Хеммінг чисел:\n";
    for (int i = 0; i < min(30, (int)nonHamming.size()); i++) {
        cout << setw(4) << nonHamming[i];
        if ((i + 1) % 15 == 0) cout << endl;
    }
    cout << "\n(Це числа, які мають у розкладі прості множники >= 5)\n";
    
    // Аналіз густини
    cout << "\n\nАналіз густини чисел Хеммінга:\n";
    cout << string(50, '=') << endl;
    
    vector<long long> ranges = {100, 500, 1000, 5000, 10000};
    for (long long range : ranges) {
        vector<long long> nums = generateHammingNumbersBrute(range);
        cout << "< " << setw(6) << range << ": " << setw(5) << nums.size() 
             << " чисел (" << fixed << setprecision(2) 
             << (100.0 * nums.size() / range) << "%)" << endl;
    }
    
    // Інтерактивна частина
    cout << "\n\n" << string(60, '=') << endl;
    cout << "Інтерактивний режим\n";
    cout << string(60, '=') << endl;
    
    while (true) {
        cout << "\nВиберіть опцію:\n";
        cout << "1 - Вивести всі числа Хеммінга < n\n";
        cout << "2 - Перевірити, чи є число числом Хеммінга\n";
        cout << "3 - Обчислити 2^k × 3^m для заданих k і m\n";
        cout << "4 - Знайти n-те число Хеммінга\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        
        int choice;
        cin >> choice;
        
        if (choice == 0) break;
        
        if (choice == 1) {
            long long n;
            cout << "Введіть n: ";
            cin >> n;
            
            vector<long long> nums = generateHammingNumbersBrute(n);
            cout << "\nЗнайдено " << nums.size() << " чисел Хеммінга < " << n << ":\n";
            printNumbers(nums, 12);
            
        } else if (choice == 2) {
            long long num;
            cout << "Введіть число: ";
            cin >> num;
            
            int k, m;
            if (isHammingNumber(num, k, m)) {
                cout << "ТАК, " << num << " = 2^" << k << " × 3^" << m << endl;
                cout << "Перевірка: 2^" << k << " × 3^" << m 
                     << " = " << (1LL << k) << " × " << computeHamming(0, m) 
                     << " = " << computeHamming(k, m) << endl;
            } else {
                cout << "НІ, " << num << " не є числом Хеммінга\n";
                cout << "Це число має у розкладі прості множники >= 5\n";
                
                // Розклад на множники
                long long temp = num;
                cout << "Розклад на множники: " << num << " = ";
                bool first = true;
                
                for (long long p = 2; p * p <= temp; p++) {
                    int count = 0;
                    while (temp % p == 0) {
                        temp /= p;
                        count++;
                    }
                    if (count > 0) {
                        if (!first) cout << " × ";
                        cout << p;
                        if (count > 1) cout << "^" << count;
                        first = false;
                    }
                }
                if (temp > 1) {
                    if (!first) cout << " × ";
                    cout << temp;
                }
                cout << endl;
            }
            
        } else if (choice == 3) {
            int k, m;
            cout << "Введіть k: ";
            cin >> k;
            cout << "Введіть m: ";
            cin >> m;
            
            long long result = computeHamming(k, m);
            if (result > 0) {
                cout << "2^" << k << " × 3^" << m << " = " << result << endl;
            } else {
                cout << "Результат занадто великий (переповнення)\n";
            }
            
        } else if (choice == 4) {
            int n;
            cout << "Введіть n (номер числа Хеммінга): ";
            cin >> n;
            
            if (n <= 0) {
                cout << "n має бути додатним!\n";
            } else {
                // Генеруємо достатньо чисел
                vector<long long> nums = generateHammingNumbersBrute(1000000);
                
                if (n <= (int)nums.size()) {
                    long long hammingN = nums[n - 1];
                    int k, m;
                    isHammingNumber(hammingN, k, m);
                    
                    cout << n << "-те число Хеммінга: " << hammingN << endl;
                    cout << "Представлення: " << hammingN << " = 2^" << k << " × 3^" << m << endl;
                } else {
                    cout << "n занадто велике! Спробуйте менше значення.\n";
                }
            }
        }
    }
    
    cout << "\nДякую за використання програми!\n";
    
    return 0;
}