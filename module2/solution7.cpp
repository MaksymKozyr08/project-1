#include <cstdio>
#include <cstdlib>

void create(int n) {
    FILE *f=fopen("arrays.txt", "w");
    if(!f)return;
    for(int i=0;i<n;i++){
        int len=rand()%6+1;
        fprintf(f, "%d ", len);
        for(int j=0;j<len;j++){
            fprintf(f, "%d ", rand() % 100);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void process(){
    FILE *f=fopen("arrays.txt", "r");
    if(!f)return;

    int bestLen=0;
    double bestAvg=-1;

    int len;
    while(fscanf(f, "%d", &len) == 1){
        double sum=0;
        int x;
        for(int i=0;i<len;i++){
            fscanf(f, "%d", &x);
            sum += x;
        }
        double avg=sum/len;
        if(avg>bestAvg){
            bestAvg=avg;
            bestLen=len;
        }
    }
    rewind(f);
    while(fscanf(f, "%d", &len)==1){
        double sum=0;
        int x;
        for(int i=0;i<len;i++)fscanf(f, "%d", &x),sum+=x;
        if(sum/len==bestAvg){
            printf("Best array: ");
            for(int i=0;i<len;i++)printf("%d ",x);
            break;
        }
    }
    fclose(f);
}

int main(){
    int n;
    scanf("%d",&n);
    create(n);
    process();
}
