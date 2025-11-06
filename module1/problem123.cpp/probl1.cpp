#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    double eps;
    cin>>eps;
    double a=1.0;
    double b=1.0+1.0/a;
    while (fabs(b-a)>eps){
        a=b;
        b=1.0+1.0/a;
    }
    cout<<b<<"\n";
    return 0;
}
