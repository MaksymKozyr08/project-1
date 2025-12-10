/*#include <iostream>
typedef long long ll;
using namespace std;
void convert(ll n,char s[]){
    if (n == 0) {
        s[0] = '0'; 
        s[1] = '\0'; 
        return;
    }
    ll i=0;
    while(n>0){
        s[i]=n%10+'0';
        i++;
        n=n/10;
    }
    s[i]='\0';
    for(ll j=0;j<i/2;++j){
        ll a=s[j];
        s[j]=s[i-j-1];
        s[i-j-1]=a;
    }
}
bool is_pailindrom(char* s){
    ll len=0;
    for(ll i=0;s[i]!='\0';++i){
        len++;
    }
    for(ll i=0;i<len/2;++i){
        if(s[i]!=s[len-1-i])return false;
    }
    return true;
}
int main(){
    char s[64];
    for(ll i=10;i<1000;++i){
        ll sq=i*i;
        convert(sq,s);
        if(is_pailindrom(s))cout<<i<<endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <math.h>
typedef long long ll;
typedef long double ld;
using namespace std;
struct point{
    ll x;
    ll y;
};
ld dist(point p1,point p2){
    return sqrt(pow((p2.x-p2.x),2)+pow((p2.y-p2.y),2));
}
void res(vector<point> &a,ll n){
    ld best=0;
    ll bestind=0;
    for(ll i=0;i<n;++i){
        best=best+dist(a[0],a[i]);
    }
    ld sum=0;
    for(ll i=1;i<n;++i){
        for(ll j=0;j<n;++j){
            sum=sum+dist(a[i],a[j]);
        }
        if(sum<best){
            best=sum;
            bestind=i;
        }
        sum=0;
    }
    cout<<bestind;
}
int main(){
    ll n;
    cin>>n;
    vector<point> a;
    for(ll i=0;i<n;++i){
        cin>>a[i].x;
        cin>>a[i].y;
    }
    res(a,n);
    return 0;
}
*/
#include <iostream>
typedef long long ll;
using namespace std;

bool task3(char* s1, char* s2){
    ll len1 = 0;
    while(s1[len1] != '\0') {
        len1++;
    }
    ll len2 = 0;
    while(s2[len2] != '\0') {
        len2++;
    }
    if(len1 != len2) return false;
    int count[256] = {0};
    for(ll i = 0; i < len1; ++i) {
        count[(unsigned char)s1[i]]++;
        count[(unsigned char)s2[i]]--;
    }
    for(int i = 0; i < 256; ++i) {
        if(count[i] != 0) return false;
    }
    return true;
}

int main() {
    char str1[] = "listen";
    char str2[] = "silent";
    char str3[] = "list";
    if(task3(str1, str2)) cout << "Yes, permutation" << endl;
    else cout << "No" << endl;
    if(task3(str1, str3)) cout << "Yes, permutation" << endl;
    else cout << "No" << endl;
    return 0;
}