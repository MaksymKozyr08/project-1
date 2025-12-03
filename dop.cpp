#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll ;
int main(){
    FILE* f=fopen("taxt.txt","r");
    if(!f)return 0;
    int n;
    vector<ll> a(n);
    for(ll i=0;i<n;++i){
        fscanf(f,"%d",&a);
    }
    fclose(f);
    ll max=a[n-1];
    for(ll i=n-2;i>=0;i--){
        if(a[i]>max){
            max=a[i];
            printf("%d",a[i]);
        }
    }
    return 0;
}