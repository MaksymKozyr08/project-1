#include <cstdio>
#include <cmath>
#include <cstdlib>

struct Equation{double a,b,c;};

void create(int N){
    FILE* f=fopen("equations.bin","wb");
    if(!f)return;
    for(int i=0;i<N;i++){
        Equation eq;
        do{eq.a=(rand()%20)-10;}while(eq.a==0);
        eq.b=(rand()%20)-10;
        eq.c=(rand()%20)-10;
        fwrite(&eq,sizeof(Equation),1,f);
    }
    fclose(f);
}

void process(){
    FILE* f=fopen("equations.bin","rb");
    if(!f)return;
    Equation eq;
    double min_r=1e9;
    double max_r=-1e9;
    int fnd=0;
    while(fread(&eq,sizeof(Equation),1,f)==1){
        double D=eq.b*eq.b-4*eq.a*eq.c;
        if(D>=0){
            double x1=(-eq.b-sqrt(D))/(2*eq.a);
            double x2=(-eq.b+sqrt(D))/(2*eq.a);
            if(x1<min_r)min_r=x1;
            if(x1>max_r)max_r=x1;
            if(x2<min_r)min_r=x2;
            if(x2>max_r)max_r=x2;
            fnd=1;
        }
    }
    fclose(f);
    if(fnd)printf("Interval: [%.2f, %.2f]\n",min_r,max_r);
    else printf("No real roots\n");
}

int main(){
    int N;
    printf("Enter N: ");
    scanf("%d",&N);
    create(N);
    process();
    return 0;
}