#include <cstdio>
#include <cstdlib>

struct Time{int h,m,s;};

int toSec(Time t){return t.h*3600+t.m*60+t.s;}

void create(int N){
    FILE* f=fopen("times.bin","wb");
    if(!f)return;
    for(int i=0;i<N;i++){
        Time t;
        t.h=rand()%24;
        t.m=rand()%60;
        t.s=rand()%60;
        fwrite(&t,sizeof(Time),1,f);
    }
    fclose(f);
}

void process(){
    FILE* f=fopen("times.bin","rb");
    if(!f)return;
    Time t;
    int min_s=1000000,max_s=-1;
    while(fread(&t,sizeof(Time),1,f)){
        int s=toSec(t);
        if(s<min_s)min_s=s;
        if(s>max_s)max_s=s;
    }
    fclose(f);
    if(max_s!=-1){
        int diff=max_s-min_s;
        printf("Interval: %02d:%02d:%02d\n",diff/3600,(diff%3600)/60,diff%60);
    }
}

int main(){
    int N;
    printf("Enter N: ");
    scanf("%d",&N);
    create(N);
    process();
    return 0;
}