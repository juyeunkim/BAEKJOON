#include <iostream>
#include <queue>

using namespace std;

char map[101][101];
int visited[101][101];
int n,m;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void bfs(){
    int x=1,y=1;
    queue<pair<int, int>> q;
    q.push(pair<int, int>(x,y));
    visited[x][y] = 1;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        if(x==n && y==m) return;
        
        for(int i=0; i<4; i++){
            int xx = x + dx[i]; int yy = y + dy[i];
            
            if(xx < 1 || yy<1 || xx>n || yy>m) continue;
            
            
            if(map[xx][yy]=='1' && visited[xx][yy] == 0) {
                q.push(pair<int, int>(xx,yy));
                visited[xx][yy] = visited[x][y]+1;
            }
        }
    }
    
}

int main(){
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>map[i][j];
            visited[i][j] = 0;
        }
    }
    
    bfs();
    cout<<visited[n][m]<<endl;

    return 0;
}
