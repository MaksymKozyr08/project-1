#include <cstdio>
#include <cstdlib>

struct Point{double x,y;};

void create(int N){
    FILE* f=fopen("points.bin","wb");
    if(!f)return;
    for(int i=0;i<N;i++){
        Point p;
        p.x=(rand()%20)-10;
        p.y=(rand()%20)-10;
        fwrite(&p,sizeof(Point),1,f);
    }
    fclose(f);
}

void process(){
    FILE* f=fopen("points.bin","rb");
    if(!f)return;
    Point p;
    double minx=1e9,maxx=-1e9,miny=1e9,maxy=-1e9;
    while(fread(&p,sizeof(Point),1,f)){
        if(p.x<minx)minx=p.x;
        if(p.x>maxx)maxx=p.x;
        if(p.y<miny)miny=p.y;
        if(p.y>maxy)maxy=p.y;
    }
    printf("Rect: x[%.1f, %.1f] y[%.1f, %.1f]\n",minx,maxx,miny,maxy);
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