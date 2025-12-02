#include <cstdio>
#include <cstring>

int main() {
    FILE* in=fopen("program.c", "r");
    FILE* out=fopen("comments.txt", "w");
    if(!in || !out)return 1;
    char line[500];
    bool insideComment=false;
    while(fgets(line, sizeof(line), in)){
        char* start;
        char* end;
        if(!insideComment){
            start=strstr(line, "/*");
            if(start){
                insideComment=true;
                start+=2;
                end=strstr(start, "*/");
                if(end){
                    *end='\0';
                    fprintf(out, "%s\n", start);
                    insideComment=false;
                }else{
                    fprintf(out, "%s", start);
                }
            }
        } 
        else{
            end=strstr(line, "*/");
            if(end){
                *end='\0';
                fprintf(out, "%s\n", line);
                insideComment=false;
            }else{
                fprintf(out, "%s", line);
            }
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}
