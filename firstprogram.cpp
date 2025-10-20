#include <iostream>
#include <cmath>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define maxll 9223372036854775807
#define maxint 2147483647

using namespace std;

ld function(ld x){
    return pow(x,2)-2;
}

ld function_d(ld x){
    ld h = 1e-8;
    return (function(x + h) - function(x)) / h;
}

int main() {
    ld x1=0,x;
    cin>>x;
    for(ll i=0;i<1e+3;++i){
        x1=x-function(x)/function_d(x);
        if(abs(function(x1))<1e-5){
            cout<<x1;
            return 0;
        }
        if(abs(function_d(x))<1e-5){
            cout<<"-1-";
            return 0;
        }
        x=x1;
    }
    return 0;
}