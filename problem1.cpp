#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
bool check(const vector<ll>&a){
    for(ll i=0;i<a.size();i++){
        if(a[i]==i+1)return false;
    }
    return true;
}
void newpermutations(vector<ll>&a,ll l,ll r){
    if(l==a.size()){
        //if(check(a)){
            cout<<"result:";
            for(ll x:a)cout<<x<<" ";
            cout<<"\n";
       //}
        return;
    }
    for(ll i=l;i<a.size();i++){
        if(a[i]!=(l+1)){
            swap(a[l],a[i]);
            newpermutations(a,l+1,a.size());
            swap(a[l],a[i]);
        }
    }
}
int main(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)a[i]=i+1;
    newpermutations(a,0,n);
    return 0;
}