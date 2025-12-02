#include <iostream>
#include <string>
#include <algorithm> // Необхідно для reverse
#include <vector>

using namespace std;
typedef long long ll;

bool isPalindrom(const string &s) {
    ll n = s.size();
    for (ll i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    ll n = s.size();
    
    if(isPalindrom(s))cout<<"1";
    ll k = n - 1; 
    for (ll len = n; len >= 1; --len) {
        if (isPalindrom(s.substr(n - len, len))) {
            k = n - len;
            break; 
        }
    }
    ll k1 = n - 1;
    for (ll len = n; len >= 1; --len) {
        if (isPalindrom(s.substr(0, len))) {
            k1 = n - len;
            break;
        }
    }
    cout<<min(k,k1)<<"\n";
    if (k < k1) {
        string to_add = s.substr(0, k);
        reverse(to_add.begin(), to_add.end());
        cout << to_add;
    } else {
        string to_add = s.substr(n - k1, k1);
        reverse(to_add.begin(), to_add.end());
        cout << to_add;
    }
    
    return 0;
}