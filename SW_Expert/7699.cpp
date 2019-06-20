#include <iostream>
using namespace std;

char map[20][20];
bool alpha[26];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int r,c,ans = 0;

/*
 ## 답이 계속 실패였던 점
 1) dfs인데 bfs로 풀었기 때문에 - 주변의 알파벳도 포함되었다
 2) 굳이 visited[][]를 체크해서 방문해야할 부분을 방문을 못하였다
 */


/*
 dfs 사용
 1) (0,0)에서 출발해서 상하좌우 중에 포함되지(방문) 않은
 (xx,yy) 의 alpha 배열을 방문
 
 2) alpha의 index을 구해서 - 아스키 코드 이용
 배열에 저장
 
 3) 모든 경우를 체크해야하기 때문에
 alpha[index] = true;
 dfs(xx,yy);
 alpha[index] = false; 이용
 
 4) 계산이 종료되면, 0~25까지 alpha의 개수를 체크 -> 더 큰 값을 ans에 대입
 */

void dfs(int x, int y){
    
    // x,y 행의 값을 alpha 배열에 넣어준다 -> 알파벳이 중복되지 않도록
    
    int index = map[x][y] - 'A';
    alpha[index] = true;
    
    
    for(int i=0; i<4; i++){
        // 1 + 2
        int xx = dx[i] + x;
        int yy = dy[i] + y;
        
        index = map[xx][yy] - 'A';
        
        if(xx <0 || yy<0 || xx>=r || yy>= c || alpha[index]) continue;
        
        //방문한적 없고, 알파벳이 처음인 xx,yy 방문
        // 3
        if(!alpha[index]){
            alpha[index] = true;
            dfs(xx,yy);
            alpha[index] = false;
            
        }
        
    }
    
    int result = 0;
    
    // 4
    for(int i=0; i<26; i++){
        if(alpha[i]) result++;
    }
    
    if(result > ans) ans = result;
    
}

int main(){
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        ans = 1;
        cin>>r>>c;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin>>map[i][j];
            }
        }
        
        for(int i=0; i<26; i++) alpha[i] = false;
        
        dfs(0, 0);
        
        
        cout<<"#"<<t<<" "<<ans<<endl;
    }
}


