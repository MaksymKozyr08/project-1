#include <iostream>

void partK(int rem,int k,int min_val,int* arr,int len){
    if(k==0){
        if(rem==0){
            for(int i=0;i<len;i++)std::cout<<arr[i]<<((i==len-1)?"\n":"+");
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
    std::cin>>N>>K;
    int* arr=new int[N];
    partK(N,K,1,arr,0);
    delete[] arr;
    return 0;
}