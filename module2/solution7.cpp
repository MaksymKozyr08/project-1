#include <cstdio>

int main() {
    FILE* f=fopen("input.txt", "r");
    if(!f)return 1;
    int n;
    fscanf(f, "%d", &n);
    int* arr=new int[n];
    for(int i=0;i<n;i++)fscanf(f, "%d", &arr[i]);
    fclose(f);
    int l=0, r=n-1;
    while(l<r){
        while(l<r && arr[l]%2==0)l++;
        while(l<r && arr[r]%2!=0)r--;
        if(l<r){
            int tmp=arr[l];
            arr[l]=arr[r];
            arr[r]=tmp;
            l++;
            r--;
        }
    }
    for(int i=0;i<n;i++)printf("%d ", arr[i]);
    delete[] arr;
    return 0;
}