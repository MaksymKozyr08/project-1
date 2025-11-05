#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
bool gt(string &s,ll a,ll b){
    for(ll i=0;i<(b-a)/2;++i){
        if(s[a+i]==s[b-1-i]){

        }
        else{
            return false;
        }
    }
    return true;
}
int main() {
    string s;
    getline(cin,s);
    ll k=0,a=0;
    for(ll i=0;i<=s.size();i++){
        if(s[i]==' ' || i==s.size()){
            if(i>a && gt(s,a,i)){
                for(ll j=a;j<i;++j){
                    cout<<s[j];
                }
                cout<<"\n";
            } 
            a=i+1;
        }        
    }
    return 0;
}
