#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <cmath>
typedef long long ll;
using namespace std;
int main(){
    /*ll n;
    cin>>n;
    vector<vector<ll>> a(n,vector<ll>(n));
    /*for(ll i=0;i<n;++i){
        for(ll j=0;j<n;++i)
        a[i][j]=rand()%100;
    }
    a = {
        {2, 3, 1, 4, 5},
        {3, 6, 2, 1, 3},
        {1, 2, 4, 3, 2},
        {4, 1, 3, 5, 4},
        {5, 3, 2, 4, 6}
    };
    vector<ll> resr(n);
    ll sum=0;
    for(ll i=0;i<n;++i){
        sum=0;
        for(ll j=0;j<n;++j){
            sum=sum+a[i][j];
            //cout<<sum<<" ";
        }
        if(i!=0 && sum!=resr[i-1]){
            cout<<"-1";
            return 0;
        }
        //cout<<sum<<" ";
        resr[i]=sum;
    }
    sum=0;
    vector<ll> resc(n);
    for(ll i=0;i<n;++i){
        for(ll j=0;j<n;++j){
            sum=sum+a[j][i];
        }
        if(i!=0 && sum!=resc[i-1]){
            cout<<"-1";
            return 0;
        }
        resc[i]=sum;
        sum=0;
    }
    cout<<"1";
    */
    char a[5];
    cin>>a;
    for(ll i=0;i<5;++i){
        cout<<a[i];
    }
    return 0;
}