#include <cstdio>
#include <cstdlib>

void create(int n, int k) {
    FILE *f=fopen("matrix.txt", "w");
    if(!f)return;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int val=rand()%100;
            fprintf(f, "%d ", val);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void process(int n,int k){
    FILE *f=fopen("matrix.txt", "r");
    if(!f)return;
    int *sum=new int[k] {};
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            fscanf(f, "%d", &x);
            sum[j]+=x;
        }
    }
    for(int j=0;j<k;j++){
        printf("Sum %d = %d\n", j, sum[j]);
    }
    delete[] sum;
    fclose(f);
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    create(n, k);
    process(n, k);
    return 0;
}