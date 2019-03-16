/*
map에서 지뢰가 있으면 8방향에 값증가 bomb[x][y]++
bomb[x][y] 이 0이면 dfs로 연쇄적 이동 && ans 증가

map에서 방문안한곳은 하나하나 선택해야하므로 ans증가

*/

#include <iostream>

using namespace std;

char map[301][301];
int bomb[301][301];
bool visited[301][301];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int n,ans =0;

void dfs(int x, int y){
    //cout<<"x y "<<x<<" "<<y<<endl;
    
    visited[x][y] = true;
    
    for(int m=0; m<8; m++){
        int xx = x+dx[m];
        int yy = y+dy[m];
        if(xx <1 || yy<1 || xx>n || yy>n) continue;
        //cout<<"xx yy "<<xx<<" "<<yy<<endl;
        
        // 연쇄적인 이동
        if(bomb[xx][yy]==0 && !visited[xx][yy]) dfs(xx, yy);
        visited[xx][yy] = true;
    }
    
    
}


int main(){
    int T;
    cin>>T;
    
    for(int t=1; t<=T; t++){
        cin>>n;
        
        ans = 0;
        
        //초기화
        for(int i=1; i<301; i++){
            for(int j=1; j<301; j++){
                bomb[i][j] = 0;
                visited[i][j] = false;
            }
        }
        
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin>>map[i][j];
                
                // map 주위에 지뢰가있는지 확인
                if(map[i][j]=='*'){
                    visited[i][j] = true;
                    for(int m=0; m<8; m++){
                        int xx = i+dx[m];
                        int yy = j+dy[m];
                        if(xx <1 || yy<1 || xx>n || yy>n) continue;
                        
                        bomb[xx][yy]++;
                    }
                }
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                // 연쇄적인 이동
                if(bomb[i][j]==0 && !visited[i][j]) { //cout<<"dfs"<<endl;
                    ans++; dfs(i, j);}
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                // 나머지 이동해야하는 갯수
                if(!visited[i][j]) { ans++;}
            }
        }
        
        
        cout<<"#"<<t<<" "<<ans<<endl;
        
        
    }
    
    
    
    
    return 0;
}
