#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    ll a;
    cin>>a;
    ld sum=0;
    ll count=0;
    for(ld i=1;sum<=a;++i){
        sum=sum+(1.0/i);
        if(sum>a)cout<<i;
    }
    return 0;
}
