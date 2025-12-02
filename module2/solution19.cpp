#include <cstdio>
#include <cstdlib>

struct Complex{double re,im;};

void create(int N){
    FILE* f=fopen("complex.bin","wb");
    if(!f)return;
    for(int i=0;i<N;i++){
        Complex c;
        c.re=(rand()%20)-10;
        c.im=(rand()%20)-10;
        fwrite(&c,sizeof(Complex),1,f);
    }
    fclose(f);
}

void process(){
    FILE* f=fopen("complex.bin","rb");
    if(!f)return;
    Complex tmp,prod={1,0};
    while(fread(&tmp,sizeof(Complex),1,f)){
        double r=prod.re*tmp.re-prod.im*tmp.im;
        double i=prod.re*tmp.im+prod.im*tmp.re;
        prod.re=r;
        prod.im=i;
    }
    printf("Product: %.2f + %.2fi\n",prod.re,prod.im);
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