#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin>>n;
    vector<ll> a;
    for(ll i=0;n>0;++i){
        a.push_back(n%3);
        n=n/3;
    }
    for(ll i=0;i<a.size();++i){
        cout<<a[a.size()-i-1];
    }
    return 0;
}