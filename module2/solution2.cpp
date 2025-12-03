#include <cstdio>

int main() {
    FILE* in=fopen("program.c", "r");
    FILE* out=fopen("comments.txt", "w");
    if(!in || !out)return 1;
    int c, n;
    bool inside=false;
    while((c=fgetc(in))!=EOF){
        if(!inside){
            if(c=='/'){
                n=fgetc(in);
                if(n=='*')inside=true;
                else ungetc(n, in);
            }
        }
        else{
            if(c=='*'){
                n=fgetc(in);
                if(n=='/'){
                    inside=false;
                    fputc('\n', out);
                }else{
                    fputc(c, out);
                    ungetc(n, in);
                }
            }else fputc(c, out);
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}