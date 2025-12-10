/*#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
ll diln(ll a,ll k){
    ll sum=0;
    for(ll i=1;i*i<=a;++i){
        if(a%i==0){
            if(i*i==a)sum=sum+a/i;
            else{
                sum=sum+a/i+i;
            }
        }
    }
    if(sum>k)return sum;
    else{
        return k;
    }
}
int main(){
    ll n;
    ll k=0;
    cin>>n;
    for(ll i=1;i<=n;++i){
        k=diln(i,k);
    }

    cout<<k;
    return 0;
}

#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int main(){
    ll n;
    ll count=0;
    cin>>n;
    vector<vector<ll>> a(n,vector<ll>(n));
    for(ll i=0;i<n;++i){
        for(ll j=0;j<n;++j){
            cin>>a[i][j];
        }
    }
    for(ll i=0;i<n-1;++i){
        for(ll j=0;j<n-1;++j){
            ll q=a[i][j];
            ll w=a[i+1][j];
            ll e=a[i][j+1];
            ll r=a[i+1][j+1];
            if(q!=w && q!=e && q!=r && w!=e && w!=r && e!=r)count++;
        }
    }
    cout<<count;
    return 0;
}*/
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

void check(char* V,char* W){
    ll sizeW=0;
    for(ll i=0;W[i]!='\0';++i){
        sizeW++;
    }
    sort(W,W+sizeW);
    ll k=0;
    for(ll i=0;V[i]!='\0';++i){
        if(!(binary_search(W,W+sizeW,V[i]))){
            V[k]=V[i];
            k++;
        }
    }
    V[k]='\0';
}


int main(){
    char V[100];
    char W[100];
    cin>>V;
    cin>>W;
    check(V,W);
    cout<<V<<endl;
    return 0;
}