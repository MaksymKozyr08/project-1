#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<ll>>dp(s1.size()+1,vector<ll>(s2.size()+1,0));
    ll count=0;
    ll index=0;
    for(ll i=1;i<=s1.size();i++){
        for(ll j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;    
                if(dp[i][j]>count){
                    count=dp[i][j];
                    index=i;
                }
            }else dp[i][j]=0;
        }
    }
    for(ll i=index-count; i<index; i++){
        cout<<s1[i];
    }
    return 0;
}
