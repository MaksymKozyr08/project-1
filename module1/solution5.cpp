#include <iostream>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin>>n;
    ll k=0;
    bool even=(n%2==0);
    for (ll p=3;p<=n;p*=3){
        ll total=n/p;
        ll even_mult=n/(2*p);
        if(even){
            k=k+even_mult;
        } 
        else{
            k=k+total-even_mult;
        }
    }
    cout << k;
    return 0;
}
