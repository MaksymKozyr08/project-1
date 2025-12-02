#include <cstdio>

void subEvenMin(int start,int k,int n,int evens,int min_ev,int* arr,int len){
    if(k==0){
        if(evens>=min_ev){
            for(int i=0;i<len;i++)printf("%d ",arr[i]);
            printf("\n");
        }
        return;
    }
    for(int i=start;i<=n;i++){
        arr[len]=i;
        subEvenMin(i+1,k-1,n,evens+(i%2==0),min_ev,arr,len+1);
    }
}

int main(){
    int N,K;
    printf("Enter N K: ");
    scanf("%d%d",&N,&K);
    int* arr=new int[K];
    subEvenMin(1,K,N,0,K/2,arr,0);
    delete[] arr;
    return 0;
}