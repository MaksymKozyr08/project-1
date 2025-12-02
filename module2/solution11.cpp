#include <cstdio>

int main(){
    FILE* in=fopen("input.txt","r");
    if(!in)return 1;
    int N;
    fscanf(in,"%d",&N);
    int* arr=new int[N];
    long long total=0;
    for(int i=0;i<N;i++){
        fscanf(in,"%d",&arr[i]);
        total+=arr[i];
    }
    fclose(in);
    long long left=0;
    int idx=-1;
    for(int i=0;i<N;i++){
        long long right=total-left-arr[i];
        if(left==right){
            idx=i;
            break;
        }
        left+=arr[i];
    }
    printf("%d",idx);
    delete[] arr;
    return 0;
}