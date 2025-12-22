#include <iostream>
#include <vector>

typedef long long ll;
typedef long double ld;

using namespace std;

bool sum_diln_check(ll n){
    ll sum=1;
    if (n <= 1) return false;
    for(ll i=2;i*i<=n;++i){
        if(n%i==0){
            if(i*i<n)sum=sum+n/i+i;
            else{
                sum=sum+n/i;
            }
        }
    }
    if(sum==n)return true;
    else{return false;}
}

void res(ll n){
    for(ll i=0;i<n;++i){
        if(sum_diln_check(i))cout<<i<<endl;
    }
}

int main(){
    ll n;
    cin>>n;
    res(n);
    return 0;
}