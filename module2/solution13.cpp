#include <cstdio>
#include <cstdlib>

struct Vector3{double x,y,z;};

void create(int N){
    FILE* f=fopen("vectors.bin","wb");
    if(!f)return;
    for(int i=0;i<N;i++){
        Vector3 v={(double)(rand()%10),(double)(rand()%10),(double)(rand()%10)};
        fwrite(&v,sizeof(Vector3),1,f);
    }
    fclose(f);
}

void process(){
    FILE* f=fopen("vectors.bin","rb");
    if(!f)return;
    Vector3 v,sum={0,0,0};
    while(fread(&v,sizeof(Vector3),1,f)){
        sum.x+=v.x;
        sum.y+=v.y;
        sum.z+=v.z;
    }
    printf("Sum: %.2f %.2f %.2f\n",sum.x,sum.y,sum.z);
    fclose(f);
}

int main(){
    int N;
    printf("Enter N: ");
    scanf("%d",&N);
    create(N);
    process();
    return 0;
}