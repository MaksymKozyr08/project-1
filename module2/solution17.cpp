#include <cstdio>
#include <cstdlib>

struct Fraction{int num,den;};

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

void create(int N){
    FILE* f=fopen("fracs.bin","wb");
    if(!f)return;
    for(int i=0;i<N;i++){
        Fraction fr;
        fr.num=rand()%10+1;
        fr.den=rand()%10+1;
        fwrite(&fr,sizeof(Fraction),1,f);
    }
    fclose(f);
}

void process(){
    FILE* f=fopen("fracs.bin","rb");
    if(!f)return;
    Fraction tmp,sum={0,1};
    while(fread(&tmp,sizeof(Fraction),1,f)){
        sum.num=sum.num*tmp.den+tmp.num*sum.den;
        sum.den=sum.den*tmp.den;
        int d=gcd(abs(sum.num),sum.den);
        sum.num/=d;
        sum.den/=d;
    }
    printf("Sum: %d/%d\n",sum.num,sum.den);
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