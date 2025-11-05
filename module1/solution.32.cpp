#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll number(string &s,ll a,ll b){
    ll num=0;
    for(ll i=a;i<b;++i){
        num=num*10+(s[i]-'0');
    }
    return num;
}

int main() {
    string s;
    cin>>s;
    ll a=-1;
    ll sum=0;
    for(ll i=0;i<s.size();++i){
        if(s[i]>='0' && s[i]<='9'){
            if(a==-1) a=i;
        } else {
            if(a!=-1){
                sum+=number(s,a,i);
                a=-1;
            }
        }
    }
    if(a!=-1) sum+=number(s,a,s.size());
    cout<<sum;
    return 0;
}
