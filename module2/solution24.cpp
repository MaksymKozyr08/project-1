#include <cstdio>

void part(int rem,int min_v,int* arr,int len){
    if(rem==0){
        for(int i=0;i<len;i++)printf("%d%s",arr[i],(i==len-1)?"\n":"+");
        return;
    }
    for(int i=min_v;i<=rem;i++){
        arr[len]=i;
        part(rem-i,i+1,arr,len+1);
    }
}

int main(){
    int N;
    printf("Enter N: ");
    scanf("%d",&N);
    int* arr=new int[N];
    part(N,1,arr,0);
    delete[] arr;
    return 0;
}