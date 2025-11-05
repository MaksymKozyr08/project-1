#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

pair<ll,ll> diln(ll a){
    ll count = 0;
    ll sum = 0;
    for (ll i = 1; i * i <=a; ++i) {
        if (a % i == 0) {
            count++;
            sum += i;
            if (i != a / i) {
                count++;
                sum += a / i;
            }
        }
    }
    return make_pair(count, sum);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    auto[count,sum]=diln(n);
    if((count*n)%sum==0)cout<<"YES";
    else{
        cout<<"NO";
    }
    return 0;
}