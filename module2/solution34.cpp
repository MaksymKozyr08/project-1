#include <cstdio>
#include <cstdlib>

int N_sz;
int** mat;
int** visited;

struct Res{int area;int perim;};

Res dfs(int r,int c){
    if(r<0||c<0||r>=N_sz||c>=N_sz||mat[r][c]==0)return {0,0};
    if(visited[r][c])return {0,0};
    visited[r][c]=1;
    int p=0;
    int dr[]={1,-1,0,0};
    int dc[]={0,0,1,-1};
    for(int k=0;k<4;k++){
        int nr=r+dr[k];
        int nc=c+dc[k];
        if(nr<0||nc<0||nr>=N_sz||nc>=N_sz||mat[nr][nc]==0)p++;
    }
    Res total={1,p};
    for(int k=0;k<4;k++){
        Res sub=dfs(r+dr[k],c+dc[k]);
        total.area+=sub.area;
        total.perim+=sub.perim;
    }
    return total;
}

int main(){
    printf("Enter n: ");
    scanf("%d",&N_sz);
    mat=new int*[N_sz];
    visited=new int*[N_sz];
    for(int i=0;i<N_sz;i++){
        mat[i]=new int[N_sz];
        visited[i]=new int[N_sz];
        for(int j=0;j<N_sz;j++){
            mat[i][j]=rand()%2;
            visited[i][j]=0;
        }
    }
    for(int i=0;i<N_sz;i++){
        for(int j=0;j<N_sz;j++)printf("%d ",mat[i][j]);
        printf("\n");
    }
    int max_a=0,res_p=0;
    for(int i=0;i<N_sz;i++){
        for(int j=0;j<N_sz;j++){
            if(mat[i][j]==1&&!visited[i][j]){
                Res r=dfs(i,j);
                if(r.area>max_a){
                    max_a=r.area;
                    res_p=r.perim;
                }
            }
        }
    }
    printf("Perimeter: %d\n",res_p);
    for(int i=0;i<N_sz;i++){delete[] mat[i];delete[] visited[i];}
    delete[] mat;delete[] visited;
    return 0;
}