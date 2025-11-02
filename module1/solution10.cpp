#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculateSum(double epsilon) {
    double sum = 0.0;
    int k = 0;
    double currentTerm = 0.0;  // При k=0: (-1)^0 * 0^2 / 0! = 0
    double factorialK = 1.0;
    int sign = 1;
    
    while (true) {
        sum += currentTerm;
        
        k++;
        factorialK *= k;
        sign = -sign;
        double nextTerm = sign * (k * k) / factorialK;
        
        if (fabs(nextTerm) < epsilon) {
            break;
        }
        
        currentTerm = nextTerm;
        
        if (k > 100) break;
    }
    
    return sum;
}

int main() {
    double epsilon;
    cin >> epsilon;
    
    double result = calculateSum(epsilon);
    cout << fixed << setprecision(10) << result << endl;
    
    return 0;
}