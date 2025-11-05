#include <iostream>
#include <cmath>
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
    for(ll i=1;i<n;i=i*2){
        for(ll j=1;j<n;j=j*3){
            if(i+j==n){
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}