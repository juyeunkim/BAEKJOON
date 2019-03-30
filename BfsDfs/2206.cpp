#include <iostream>
#include <queue>

using namespace std;

char map[1001][1001];
bool visited[1001][1001][2];
int n,m;
int ans = -1;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x, y));
    queue<pair<int,int>> wall;
    wall.push(make_pair(0, 1));
    
    visited[x][y][0] = true;
    
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        int wall_cnt = wall.front().first;
        int cnt = wall.front().second;
        
        q.pop(); wall.pop();
        
        if(cur_x == n && cur_y == m){
            if(ans < cnt) ans = cnt;
            break;
        }
        
        for(int i=0; i<4; i++){
            int xx = cur_x + dx[i], yy = cur_y + dy[i];
            if(xx<1 || yy<1 || xx>n || yy>m || visited[xx][yy][wall_cnt]) continue;
            
            if(map[xx][yy] == '0') { 
                q.push(make_pair(xx, yy)); wall.push(make_pair(wall_cnt, cnt+1));}
            else if(map[xx][yy] == '1' && wall_cnt == 0) {
                q.push(make_pair(xx, yy)); wall.push(make_pair(wall_cnt+1, cnt+1));}
            
            
            
            if(xx == n && yy == m){
                if(ans < cnt) ans = cnt;
                break;
            }
            
            visited[xx][yy][wall_cnt] = true;
            
        }
        
        
    }
    
    
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1; j<=m; j++) {
            cin>>map[i][j];
            visited[i][j][0] = false;visited[i][j][1] = false;
            
        }
    }
    
    bfs(1, 1);
    cout<<ans;
    
    return 0;
}

