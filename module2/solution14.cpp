#include <cstdio>
#include <cstdlib>

struct Rect{double x1,y1,x2,y2;};

void create(int N){
    FILE* f=fopen("rects.bin","wb");
    if(!f)return;
    for(int i=0;i<N;i++){
        Rect r;
        r.x1=rand()%10;
        r.y1=rand()%10;
        r.x2=r.x1+(rand()%10)+1;
        r.y2=r.y1+(rand()%10)+1;
        fwrite(&r,sizeof(Rect),1,f);
    }
    fclose(f);
}

void process(){
    FILE* f=fopen("rects.bin","rb");
    if(!f)return;
    Rect r,res;
    if(fread(&res,sizeof(Rect),1,f)!=1){fclose(f);return;}
    while(fread(&r,sizeof(Rect),1,f)){
        res.x1=(res.x1>r.x1)?res.x1:r.x1;
        res.y1=(res.y1>r.y1)?res.y1:r.y1;
        res.x2=(res.x2<r.x2)?res.x2:r.x2;
        res.y2=(res.y2<r.y2)?res.y2:r.y2;
    }
    if(res.x1<res.x2&&res.y1<res.y2)
        printf("Intersection: %.1f %.1f %.1f %.1f\n",res.x1,res.y1,res.x2,res.y2);
    else printf("No intersection\n");
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