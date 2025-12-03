#include <iostream>

void part(int rem,int min_val,int* arr,int len){
    if(rem==0){
        for(int i=0;i<len;i++){
            std::cout<<arr[i]<<((i==len-1)?"\n":"+");
        }
        return;
    }
    for(int i=min_val;i<=rem;i++){
        arr[len]=i;
        part(rem-i,i,arr,len+1);
    }
}

int main(){
    int N;
    std::cout<<"Enter N: ";
    std::cin>>N;
    int* arr=new int[N];
    part(N,1,arr,0);
    delete[] arr;
    return 0;
}