#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
void gt(string &s,ll a,ll b){
    for(ll i=0;i<(b-a)/2;++i){
        char c=s[a+i];
        s[a+i]=s[b-1-i];
        s[b-1-i]=c;
    }
}
int main() {
    string s;
    getline(cin,s);
    ll k=0,a=0;
    for(ll i=0;i<=s.size();i++){
        if(s[i]==' ' || i==s.size()){
            if(i>a) gt(s,a,i);//reverse(s.begin()+a,s.begin()+i);
            a=i+1;
        }        
    }
    cout<<s;
    return 0;
}
