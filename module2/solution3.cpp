#include <cstdio>

int main() {
    FILE* in=fopen("words.txt", "r");
    FILE* sh=fopen("short.txt", "w");
    FILE* lg=fopen("long.txt", "w");
    if(!in || !sh || !lg)return 1;
    int c, len=0;
    char buf[101];
    while((c=fgetc(in))!=EOF){
        if(c==' ' || c=='\n'){
            if(len>0){
                buf[len]='\0';
                if(len<4)fprintf(sh, "%s\n", buf);
                else fprintf(lg, "%s\n", buf);
                len=0;
            }
        }else{
            if(len<100)buf[len++]=c;
        }
    }
    if(len>0){
        buf[len]='\0';
        if(len<4)fprintf(sh, "%s\n", buf);
        else fprintf(lg, "%s\n", buf);
    }
    fclose(in);
    fclose(sh);
    fclose(lg);
    return 0;
}