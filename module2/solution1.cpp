#include <cstdio>
#include <string>
using namespace std;

int main() {
    FILE* in=fopen("source.c", "r");
    if (!in) return 1;
    FILE* out=fopen("comments.txt", "w");
    if(!out){
        fclose(in);
        return 1;
    }
    char buffer[1000];
    while(fgets(buffer,sizeof(buffer),in)){
        string line=buffer;
        size_t pos=line.find("//");
        if(pos!=string::npos){
            string comment = line.substr(pos + 2);
            fputs(comment.c_str(), out);
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}   