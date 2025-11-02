#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculateSum(double epsilon) {
    double sum = 0.0;
    int k = 0;
    double currentTerm = 1.0;  // При k=0: (-2)^0 / 0! = 1 / 1 = 1
    double factorialK = 1.0;
    double powerOf2 = 1.0;     // (-2)^k
    
    while (true) {
        sum += currentTerm;
        
        k++;
        factorialK *= k;
        powerOf2 *= (-2);
        double nextTerm = powerOf2 / factorialK;
        
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