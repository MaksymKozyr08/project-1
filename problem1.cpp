#include <iostream>
#include <vector>
using namespace std;
bool check(const vector<int>&a){
    for(int i=0;i<a.size();i++){
        if(a[i]==i+1)return false;
    }
    return true;
}
void newpermutations(vector<int>&a,int l,int r){
    if(l==a.size()){
        if(check(a)){
            cout<<"result:";
            for(int x:a)cout<<x<<" ";
            cout<<"\n";
        }
        return;
    }
    for(int i=l;i<a.size();i++){
        swap(a[l],a[i]);
        newpermutations(a,l+1,a.size());
        swap(a[l],a[i]);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)a[i]=i+1;
    newpermutations(a,0,n);
    return 0;
}