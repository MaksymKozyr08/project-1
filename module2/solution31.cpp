#include <cstdio>
#include <cstdlib>
#include <cmath>

void perm(int* p,int* used,int n,int k,int len){
    if(len==n){
        for(int i=0;i<n;i++)printf("%d ",p[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            if(abs(i-(len+1))<=k){
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
    printf("Enter n k: ");
    scanf("%d%d",&n,&k);
    int* p=new int[n];
    int* used=new int[n+1];
    for(int i=0;i<=n;i++)used[i]=0;
    perm(p,used,n,k,0);
    delete[] p;
    delete[] used;
    return 0;
}