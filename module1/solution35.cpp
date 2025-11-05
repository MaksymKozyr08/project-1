#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

bool isPal(string &s, ll a, ll b){
    while(a < b){
        if(s[a] != s[b]) return false;
        a++;
        b--;
    }
    return true;
}

int main(){
    string s;
    getline(cin, s);
    ll n = s.size();
    ll add = 0;

    for(ll i = 0; i < n; i++){
        if(isPal(s, i, n - 1)){
            add = i;
            break;
        }
    }

    if(n + add > s.capacity()){
        cout << "Not enough space";
        return 0;
    }

    for(ll i = add - 1; i >= 0; i--){
        s.push_back(s[i]);
    }

    cout << s;
    return 0;
}
