#include <iostream>

void subEven(int start,int k,int n,int evens,int target,int* arr,int len){
    if(k==0){
        if(evens==target){
            for(int i=0;i<len;i++)std::cout<<arr[i]<<" ";
            std::cout<<"\n";
        }
        return;
    }
    for(int i=start;i<=n;i++){
        int is_ev=(i%2==0);
        if(evens+is_ev<=target && (len+1-evens-is_ev)<=target){ 
            arr[len]=i;
            subEven(i+1,k-1,n,evens+is_ev,target,arr,len+1);
        }
    }
}

int main(){
    int N,K;
    std::cout<<"Enter N K: ";
    std::cin>>N>>K;
    int* arr=new int[K];
    subEven(1,K,N,0,K/2,arr,0);
    delete[] arr;
    return 0;
}