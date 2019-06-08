#include <iostream>
using namespace std;

int map[100][100];
bool visited[100][100];
int n;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


/*
 
 1~100 까지 날을 map에서 확인 -> -1로 처리해서 -> dfs 사용해서
 몇등분 남았는지 체크 -> ans 와 비교해서 max값을 ans에 저장
 return ans
 */
void dfs(int x, int y){
    
    visited[x][y] = true;
    
    for(int i=0; i<4; i++){
        int xx = dx[i] + x;
        int yy = dy[i] + y;
        
        if(xx <0 || yy<0 || xx>=n || yy>= n) continue;
        if(!visited[xx][yy] && map[xx][yy]!=-1) { visited[xx][yy] = true; dfs(xx, yy);}
    }
    
}

int main(){
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        int ans = 0, tmp = 0;
        int max = -1; // 1~max 까지 치즈 나누기
        cin>>n;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>map[i][j];
                visited[i][j] = false;
                if(max < map[i][j]) max = map[i][j];
            }
        }
        
        for(int a=0; a<=max; a++){
            tmp = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    // a 번째 덩이로 나누기
                    if(map[i][j] == a) map[i][j] = -1;
                    visited[i][j] = false;
                }
            }
            
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(map[i][j]!=-1 && visited[i][j] == false) {dfs(i, j); tmp++;}
                }
            }
            // 최대 ans 값
            if(ans < tmp) ans = tmp;
        }
        
        
        
        cout<<"#"<<t<<" "<<ans<<endl;
    }
}
