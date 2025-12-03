#include <iostream>
#include <cmath>

void perm(int* p,int* used,int n,int k,int len){
    if(len==n){
        for(int i=0;i<n;i++)std::cout<<p[i]<<" ";
        std::cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            if(len==0||std::abs(p[len-1]-i)<=k){
                used[i]=1;
                p[len]=i;
                perm(p,used,n,k,len+1);
                used[i]=0;
            }
        }
    }
}

int main(){
    int n,k;
    std::cout<<"Enter n k: ";
    std::cin>>n>>k;
    int* p=new int[n];
    int* used=new int[n+1];
    for(int i=0;i<=n;i++)used[i]=0;
    perm(p,used,n,k,0);
    delete[] p;
    delete[] used;
    return 0;
}