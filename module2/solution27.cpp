#include <iostream>

void comb(int start,int k,int n,int* arr,int len){
    if(k==0){
        for(int i=0;i<len;i++)std::cout<<arr[i]<<" ";
        std::cout<<"\n";
        return;
    }
    for(int i=start;i<=n;i++){
        arr[len]=i;
        comb(i+1,k-1,n,arr,len+1);
    }
}

int main(){
    int N,K;
    std::cout<<"Enter N K: ";
    std::cin>>N>>K;
    int* arr=new int[K];
    comb(1,K,N,arr,0);
    delete[] arr;
    return 0;
}