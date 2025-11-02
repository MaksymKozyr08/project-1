#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculateProduct(double epsilon) {
    double product = 1.0;
    int k = 1;
    double currentTerm = 1.0;
    
    while (true) {
        double n = k;
        currentTerm = (2*n) * (2*n) / ((2*n - 1) * (2*n + 1));
        
        product *= currentTerm;
        
        k++;
        double n_next = k;
        double nextTerm = (2*n_next) * (2*n_next) / ((2*n_next - 1) * (2*n_next + 1));
        
        if (fabs(nextTerm - 1.0) < epsilon) {
            break;
        }
        
        if (k > 10000) break;
    }
    
    return product;
}

int main() {
    double epsilon;
    cin >> epsilon;
    
    double result = calculateProduct(epsilon);
    cout << fixed << setprecision(10) << result << endl;
    
    return 0;
}