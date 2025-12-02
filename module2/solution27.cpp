#include <cstdio>

void comb(int start,int k,int n,int* arr,int len){
    if(k==0){
        for(int i=0;i<len;i++)printf("%d ",arr[i]);
        printf("\n");
        return;
    }
    for(int i=start;i<=n;i++){
        arr[len]=i;
        comb(i+1,k-1,n,arr,len+1);
    }
}

int main(){
    int N,K;
    printf("Enter N K: ");
    scanf("%d%d",&N,&K);
    int* arr=new int[K];
    comb(1,K,N,arr,0);
    delete[] arr;
    return 0;
}