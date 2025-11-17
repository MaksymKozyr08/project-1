#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll dx = x2 - x1;
    ll dy = y2 - y1;
    double x3 = x1 - dy;
    double y3 = y1 + dx;
    cout << x3 << " " << y3;
    return 0;
}