#include <iostream>
typedef long long ll;
using namespace std;
/*
bool proste(ll n){
    if(n==1)return false;
    for(ll i=2;i*i<=n;++i){
        if(n%i==0)return false;
    }
    return true;
}

void res(ll *a,ll n){
    ll k=0;
    for(ll i=0;i<n;++i){
        if(!proste(a[i])){
            a[k++]=a[i];
        }
    }
    for(ll i=0;i<k;++i){
        cout<<a[i]<<" ";
    }
}*/
void res(char a[],ll n){
    for(ll i=0;i<n;++i){
        cout<<a[i];
    }
}
struct point{
    ll x;
    ll y;
};

int main(){
    point a[10];
    for(ll i=0;i<10;++i){
        cin>>a[i].x;
        cin>>a[i].y;
    }

    for(ll i=0;i<10;++i){
        cout<<a[i].x<<" "<<a[i].y<<endl;
    }
    return 0;
}