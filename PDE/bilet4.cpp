#include <iostream>
#include <vector>

typedef long long ll;
typedef long double ld;

using namespace std;

bool proste(ll n){
    ll sum=0;
    for(ll i=1;i*i<=n;++i){
        if(n%i==0){
            if(i*i!=n){
                sum+=2;
            }
            else{
                sum++;
            }
        }
    }
    if(n<=1)return false;
    if(sum==2)return true;
    return false;
}

void res(ll n,ll a[]){
    for(ll i=0; i<n;){
        if(!proste(a[i])){
            for(ll j=i; j<n-1; ++j){
                a[j] = a[j+1];
            }
            a[n-1] = 0;
        }
        i++;
    }

    for(ll i=0; i<n; ++i){
        cout<<a[i]<<" ";
    }
}
int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;++i){
        cin>>a[i];
    }
    res(n,a);
    return 0;
}