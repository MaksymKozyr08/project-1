#include <iostream>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll a;
    cin>>a;
    ll k=0;
    for(ll i=1;i*i<=a;++i){
        if(a%(i*i)==0){
            k=k+(i*i);
        }
    }
    cout<<k;
    return 0;
}