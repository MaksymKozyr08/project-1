#include <cstdio>

void partK(int rem,int k,int min_val,int* arr,int len){
    if(k==0){
        if(rem==0){
            for(int i=0;i<len;i++)printf("%d%s",arr[i],(i==len-1)?"\n":"+");
        }
        return;
    }
    for(int i=min_val;i<=rem;i++){
        arr[len]=i;
        partK(rem-i,k-1,i,arr,len+1);
    }
}

int main(){
    int N,K;
    printf("Enter N K: ");
    scanf("%d%d",&N,&K);
    int* arr=new int[N];
    partK(N,K,1,arr,0);
    delete[] arr;
    return 0;
}