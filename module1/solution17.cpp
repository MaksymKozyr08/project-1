#include <iostream>
#include <cmath>
using namespace std;

bool canBeRepresentedAsDifferenceOfCubes(long long n) {
    if (n < 0) {
        return false;
    }
    if (n == 0) {
        return true;
    }
    int remainder = n % 9;
    if (remainder == 2 || remainder == 3 || remainder == 4 || 
        remainder == 5 || remainder == 6) {
        return false;
    }
    long long maxA = (long long)cbrt(n) + 2;
    for (long long b = 0; b <= maxA; b++) {
        long long b3 = b * b * b;
        long long a3 = n + b3;
        long long a = (long long)round(cbrt(a3));
        if (a * a * a == a3) {
            return true;
        }
    }
    return false;
}
bool findRepresentation(long long n, long long &a, long long &b) {
    if (n < 0) {
        return false;
    }
    if (n == 0) {
        a = 0;
        b = 0;
        return true;
    }
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
    long long testCases[] = {-5, 0, 1, 2, 7, 8, 26, 27, 63, 64, 91, 100};
    for (int i = 0; i < 12; i++) {
        long long n = testCases[i];
        long long a, b;
        cout << "n = " << n << ": ";
        if (findRepresentation(n, a, b)) {
            cout << "NO" << n << " = " << a << "³ - " << b << "³ = " 
                 << (a*a*a) << " - " << (b*b*b) << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    long long n;
    
    while (cin >> n && n != 0) {
        long long a, b;
        
        if (findRepresentation(n, a, b)) {
            cout << "YES" << n << " = " << a << "³ - " << b << "³\n";
            cout << "YES" << a << "³ - " << b << "³ = " 
                 << (a*a*a) << " - " << (b*b*b) << " = " << (a*a*a - b*b*b) << endl;
        } else {
            cout << "NO" << n << "NO";
            
            if (n < 0) {
                cout << "NO";
            }
        }
    }
    
    return 0;
}