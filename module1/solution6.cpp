#include <algorithm>
#include <iostream>

typedef long long ll;
typedef long double ld;
using namespace std;

ll countp(ll n, ll p){
    ll s=0;
    while(n){
        s+=n/p;
        n/=p;
    }
    return s;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin>>n>>k;
    ll c2 = countp(n,2)-countp(k,2)-countp(n-k,2);
    ll c5 = countp(n,5)-countp(k,5)-countp(n-k,5);
    cout<<min(c2, c5);
    return 0;
}
