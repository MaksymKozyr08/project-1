#include <cstdio>
#include <cstdlib>

struct Point{int r,c;};

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int** mat=new int*[n];
    for(int i=0;i<n;i++){
        mat[i]=new int[n];
        for(int j=0;j<n;j++)mat[i][j]=rand()%2;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf("%d ",mat[i][j]);
        printf("\n");
    }
    if(mat[0][0]==0||mat[n-1][n-1]==0){
        printf("No path\n");return 0;
    }
    Point* q=new Point[n*n];
    int head=0,tail=0;
    int** dist=new int*[n];
    Point** p=new Point*[n];
    for(int i=0;i<n;i++){
        dist[i]=new int[n];
        p[i]=new Point[n];
        for(int j=0;j<n;j++)dist[i][j]=-1;
    }
    q[tail++]={0,0};
    dist[0][0]=0;
    bool found=false;
    while(head<tail){
        Point curr=q[head++];
        if(curr.r==n-1&&curr.c==n-1){found=true;break;}
        for(int dr=-1;dr<=1;dr++){
            for(int dc=-1;dc<=1;dc++){
                if(dr==0&&dc==0)continue;
                int nr=curr.r+dr,nc=curr.c+dc;
                if(nr>=0&&nc>=0&&nr<n&&nc<n&&mat[nr][nc]==1&&dist[nr][nc]==-1){
                    dist[nr][nc]=dist[curr.r][curr.c]+1;
                    p[nr][nc]=curr;
                    q[tail++]={nr,nc};
                }
            }
        }
    }
    if(found){
        Point curr={n-1,n-1};
        while(curr.r!=0||curr.c!=0){
            printf("(%d,%d)<-",curr.r,curr.c);
            curr=p[curr.r][curr.c];
        }
        printf("(0,0)\n");
    } else printf("No path\n");
    return 0;
}