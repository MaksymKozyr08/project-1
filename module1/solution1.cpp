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
    ll b=0;
    for(ll i=0;a!=0;++i){
        b=b*10;
        b=b+a%10;
        a=a/10;
    }
    cout<<b;
    return 0;
}
