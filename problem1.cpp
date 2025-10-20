#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define maxll 9223372036854775807
#define maxint 2147483647

using namespace std;
void permutation(vector<ll> &a){
    for(ll i=0;i<a.size();++i){
        for(ll j=0;j<a.size();++j){
            if(a[i]!=j && a[j]!=i){
                ll c=a[j];
                a[j]=a[i];
                a[i]=c;
            }
        }
    }
}

int main() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;++i){
        cin>>a[i];
    }
    permutation(a);
    for(ll x : a){
        cout << x << " ";
    }
    return 0;
}