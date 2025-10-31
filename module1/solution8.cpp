#include <iostream>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll b;
    cin>>b;
    ll t=b;
    ll a=b*b;
    ll r=b;
    ll check=0;
    for(ll i=0;r!=0;++i){
        check=(check*10)+(a%10);
        a=a/10;
        r=r/10;
    }
    ll p=0;
    for(ll i=0;check!=0;){
        p=(p*10)+(check%10);
        check=check/10;
    }
    if(p==t)cout<<1;
    else{
        cout<<0;
    }
    return 0;
}