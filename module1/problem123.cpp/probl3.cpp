#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
typedef long double ld;

void gt(string &s,ll a,ll b){
    for(ll i=a;i<b;++i){
        s[i]=s[i+1];
    }
}

int main(){
    string s;
    cin>>s;
    ll a=-1;
    for(ll i=0;i<s.size();++i){
        if((s[i]-'0')==0 || i==s.size()){
            if(a==-1){
                a=i;
            }
            else{
                if(a!=-1){
                    gt(s,a,i);
                    a=-1;
                }
            }
        }
    }
    if(a!=-1){
        gt(s,a,s.size());
        s=s+'0';
    }
    cout<<s;
    return 0;
}