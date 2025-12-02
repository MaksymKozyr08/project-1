#include <cstdio>
#include <cstdlib>

struct Mixed{int w,n,d;};

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

void create(int N){
    FILE* f=fopen("mixed.bin","wb");
    if(!f)return;
    for(int i=0;i<N;i++){
        Mixed m;
        m.w=rand()%5;
        m.n=rand()%5;
        m.d=(rand()%5)+1;
        fwrite(&m,sizeof(Mixed),1,f);
    }
    fclose(f);
}

void process(){
    FILE* f=fopen("mixed.bin","rb");
    if(!f)return;
    Mixed m;
    int tn=0,td=1;
    while(fread(&m,sizeof(Mixed),1,f)){
        int imp=m.w*m.d+m.n;
        tn=tn*m.d+imp*td;
        td=td*m.d;
        int com=gcd(abs(tn),td);
        tn/=com;
        td/=com;
    }
    printf("Sum: %d %d/%d\n",tn/td,tn%td,td);
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