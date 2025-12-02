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
    Point start={n-1,0},end={0,n-1};
    if(mat[start.r][start.c]==0||mat[end.r][end.c]==0){
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
    q[tail++]=start;
    dist[start.r][start.c]=0;
    int dr[]={1,-1,0,0},dc[]={0,0,1,-1};
    bool found=false;
    while(head<tail){
        Point curr=q[head++];
        if(curr.r==end.r&&curr.c==end.c){found=true;break;}
        for(int k=0;k<4;k++){
            int nr=curr.r+dr[k],nc=curr.c+dc[k];
            if(nr>=0&&nc>=0&&nr<n&&nc<n&&mat[nr][nc]==1&&dist[nr][nc]==-1){
                dist[nr][nc]=dist[curr.r][curr.c]+1;
                p[nr][nc]=curr;
                q[tail++]={nr,nc};
            }
        }
    }
    if(found){
        Point curr=end;
        while(curr.r!=start.r||curr.c!=start.c){
            printf("(%d,%d)<-",curr.r,curr.c);
            curr=p[curr.r][curr.c];
        }
        printf("(%d,%d)\n",start.r,start.c);
    } else printf("No path\n");
    return 0;
}