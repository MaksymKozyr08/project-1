#include <cstdio>
#include <cstdlib>

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int** mat=new int*[n];
    long long** dp=new long long*[n];
    for(int i=0;i<n;i++){
        mat[i]=new int[n];
        dp[i]=new long long[n];
        for(int j=0;j<n;j++){
            mat[i][j]=rand()%2;
            dp[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf("%d ",mat[i][j]);
        printf("\n");
    }
    if(mat[0][0]==1)dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                if(i>0)dp[i][j]+=dp[i-1][j];
                if(j>0)dp[i][j]+=dp[i][j-1];
            } else dp[i][j]=0;
        }
    }
    printf("Paths: %lld\n",dp[n-1][n-1]);
    for(int i=0;i<n;i++){delete[] mat[i];delete[] dp[i];}
    delete[] mat;delete[] dp;
    return 0;
}