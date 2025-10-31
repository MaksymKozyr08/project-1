#include <iostream>

typedef long long ll;
typedef long double ld;
using namespace std;

bool check(ll a){
    for(ll i=2;i*i<=a;++i){
        if(a%i==0)return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll a;
    cin>>a;
    ll k=1;
    for(ll i=1;i*i<=a;++i){
        if(a%i==0){
            if(check(i)){
                k=k*i;
            }
            ll other = a / i;
            if (other != i && check(other)) k *= other;
        }
    }
    cout<<k;
    return 0;
}