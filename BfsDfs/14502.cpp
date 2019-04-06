#include <iostream>
#include <queue>
using namespace std;

int map[9][9];
bool visited[9][9][4];
int n,m, ans = 0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

// 1) 벽을 세우고 - dfs
// 2) 감염 - bfs
// 2) 최대 영역을 비교

void spread(){
    int tmp[9][9];
    int c = 0;
    queue<pair<int, int>> q;
    // tmp에 map의 값을 넣어서 비교 -> map의 값을 변형시키기 않기 위해
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            tmp[i][j] = map[i][j];
            if(tmp[i][j] ==2) q.push(make_pair(i, j));
        }
        
    }
    
    // 주변을 감염시키기
    while(!q.empty()){
        int cur_x = q.front().first, cur_y = q.front().second;
        q.pop();
        
        for(int k=0; k<4; k++){
            int xx = cur_x+dx[k], yy = cur_y+dy[k];
            
            if(xx<=0 || yy<=0 || xx>n|| yy>m ) continue;
            
            if( tmp[xx][yy] == 0) {tmp[xx][yy] = 2; q.push(make_pair(xx, yy));}
        }
        
        
    }
    
    // 안전지대 갯수세기
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(tmp[i][j]==0) c++;
        }
    }
    //최대값 비교
    if(ans < c) ans = c;
    
    
}

void temp(int cnt){
    if(cnt == 3){
        // 감염시키기
        spread();
        return;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j]!=0) continue;
            
            // 넣고
            map[i][j] = -1;
            
            
            if(!visited[i][j][cnt] && cnt < 3){
                visited[i][j][cnt] = true; cnt++;
                temp(cnt);
                cnt--;
                visited[i][j][cnt] = false;
                
            }
            
            // 빼기
            map[i][j] = 0;
            
        }
    }
}


int main(){
    
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>map[i][j];
        }
    }
    
    temp(0);
    
    cout<<ans<<endl;
    return 0;
}


