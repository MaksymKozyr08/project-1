#include <cstdio>
#include <cstring>

int main() {
    FILE* in  = fopen("words.txt", "r");
    FILE* sh  = fopen("short.txt", "w");
    FILE* lg  = fopen("long.txt", "w");
    if(!in || !sh || !lg)return 1;
    char word[101];
    while(fscanf(in, "%100s",word)==1){
        if(strlen(word)<4)
            fprintf(sh, "%s\n",word);
        else
            fprintf(lg, "%s\n",word);
    }
    fclose(in);
    fclose(sh);
    fclose(lg);
    return 0;
}
