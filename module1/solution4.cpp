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
    if(a==0){
        cout<<0;
        return 0;
    }
    ll start=0;
    for(ll i=0;a!=0;++i){
        start=start*10+(a%3);
        a=a/3;
    }
    ll reverse=0;
    for(ll i=0;start!=0;++i){
        reverse=reverse*10+(start%10);
        start=start/10;
    }
    cout<<reverse;
    return 0;
}