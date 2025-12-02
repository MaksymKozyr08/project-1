#include <cstdio>

int main() {
    FILE *in=fopen("input.txt", "r");
    FILE *low=fopen("low.txt", "w");
    FILE *high=fopen("high.txt", "w");
    if (!in || !low || !high) return 1;
    double x;
    while(fscanf(in, "%lf", &x)==1){
        if(x < 10)fprintf(low, "%.2f ",x);
        else        
            fprintf(high, "%.2f ",x);
    }
    fclose(in);
    fclose(low);
    fclose(high);
    return 0;
}
