#include <iostream>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll a;
    cin>>a;
    ll k=1;    
    if(a<=1){
        cout<<-1;
        return 0;
    }
    for(ll i=2;i*i<=a;++i){
        if(a%i==0){
            if(i*i==a){
                if((k+i)>a){
                    cout<<-1;
                    return 0;
                }
                else{
                    k=k+i;
                }
            }
            else{
                if((k+i+(a/i))>a){
                    cout<<-1;
                    return 0;
                }
                else{
                    k=k+i+(a/i);
                }
            }
        }
    }
    if(k==a)cout<<1;
    else{
        cout<<-1;
    }
    return 0;
}