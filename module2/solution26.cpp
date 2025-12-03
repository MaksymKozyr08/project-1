#include <iostream>

void seq(int k,int n,int* arr,int len){
    if(k==0){
        for(int i=0;i<len;i++)std::cout<<arr[i]<<" ";
        std::cout<<"\n";
        return;
    }
    int start=(len==0)?1:(arr[len-1]*2);
    int step=(len==0)?1:arr[len-1];
    for(int i=start;i<=n;i+=step){
        arr[len]=i;
        seq(k-1,n,arr,len+1);
    }
}

int main(){
    int N,K;
    std::cout<<"Enter N K: ";
    std::cin>>N>>K;
    int* arr=new int[K];
    seq(K,N,arr,0);
    delete[] arr;
    return 0;
}