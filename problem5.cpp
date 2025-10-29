#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    string s;
    cin>>s;
    stack<char> a;
    vector<ll> element;
    for(ll i=0;i<s.size();++i){
        if(s[i]=='-' || s[i]=='+' || s[i]=='*' || s[i]=='/'){
            a.push(s[i]);  // push() - adds operator to top of stack
        }
        else{
            element.push_back(s[i]-'0');
        }
    }
    
    for (ll x : element) cout << x << " ";
    cout << "\n";
    for(ll i=0;i<element.size();++i){
        
    }
    
    return 0;
}
