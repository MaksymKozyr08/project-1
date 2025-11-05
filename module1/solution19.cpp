#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a;
    for(ll i=0;(i*13)<=n;i++){
        for(ll j=0;(i*13)+(j*7)<=n;j++){
            a.push_back((i*13)+(j*7));
        }
    }
    sort(a.begin(),a.end());
    for(ll x:a){
        cout<<x<<" ";
    }
    return 0;
}