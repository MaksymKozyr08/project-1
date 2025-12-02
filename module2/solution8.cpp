#include <cstdio>

int main() {
    FILE *in=fopen("input.txt", "r");
    if(!in)return 1;
    int N;
    fscanf(in, "%d",&N);
    int *arr = new int[N];
    for(int i=0;i<N;i++) fscanf(in, "%d", &arr[i]);
    fclose(in);
    int left = 0,right=N-1;
    while(left<right){
        if(arr[left]%2==0)left++;
        else if(arr[right]%2!=0)right--;
        else{
            int tmp=arr[left];
            arr[left]=arr[right];
            arr[right]=tmp;
        }
    }
    for(int i=0;i<N;i++)printf("%d ",arr[i]);
    delete[] arr;
    return 0;
}
