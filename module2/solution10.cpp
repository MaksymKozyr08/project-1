#include <cstdio>

int main(){
    FILE* in=fopen("input.txt","r");
    if(!in)return 1;
    int N;
    fscanf(in,"%d",&N);
    int* arr=new int[N];
    for(int i=0;i<N;i++)fscanf(in,"%d",&arr[i]);
    fclose(in);
    if(N>0){
        int max_r=arr[N-1];
        printf("%d ",max_r);
        for(int i=N-2;i>=0;i--){
            if(arr[i]>max_r){
                max_r=arr[i];
                printf("%d ",arr[i]);
            }
        }
    }
    delete[] arr;
    return 0;
}