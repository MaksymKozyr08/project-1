#include <cstdio>

int main(){
    int N,K;
    printf("Enter N K: ");
    scanf("%d%d",&N,&K);
    int* arr=new int[N];
    for(int i=0;i<N;i++)arr[i]=i+1;
    FILE* out=fopen("output.txt","w");
    int cnt=N;
    int idx=0;
    int step=0;
    while(cnt>0){
        if(arr[idx]!=0){
            step++;
            if(step==K){
                fprintf(out,"%d ",arr[idx]);
                arr[idx]=0;
                step=0;
                cnt--;
            }
        }
        idx++;
        if(idx==N)idx=0;
    }
    fclose(out);
    delete[] arr;
    return 0;
}