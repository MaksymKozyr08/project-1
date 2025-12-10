/*#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

void sortr(vector<ll> &a, ll n) {
    for (ll i = 0; i < n - 1; ++i) {
        for (ll j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
    for(ll i:a)cout<<i<<" ";
}
int main(){
    ll n=0;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;++i){
        cin>>a[i];
    }
    sortr(a,n);
    return 0;
}
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

void sortr(char s[]){
    for(ll i=0;s[i]!='\0';++i){
        if(i==0 || (s[i]!=' ' && s[i-1]==' '))
        s[i]=s[i]-32;
    }
    for(ll i=0;s[i]!='\0';++i){
        cout<<s[i];
    }
}
int main(){
    char s[1000];
    cin.getline(s,sizeof(s));
    sortr(s);
    return 0;
}
*/
#include <iostream>
#include <vector>

struct fraction{
	int naminator;
	int denaminator;
};
int NSD(int a, int b){
    int c;
	if (b == 0)
		int c = a;
	else 		
		int c = NSD (b, a%b);
	return c;
}
fraction task3(fraction f){
	
	int d;
	if (f.denaminator > f.naminator)
		d = NSD(f.denaminator, f.naminator);
	else 	
		d = NSD(f.naminator, f.denaminator);
	
	f.naminator /= d;
	f.denaminator /= d;
	
	return f;
}
typedef long long ll;
using namespace std;

int main(){
    fraction f1;
	f1.naminator = 12;
	f1.denaminator = 30;	
	f1 = task3(f1);	
    return 0;
}
