
#include <iostream>
using namespace std;

bool map[101][101];
bool num[101];
int n,ans = 0;

/*
 ## 답이 계속 실패였던점
 1) map을 초기화 안해줘서
 2) 서로 알고있다는 점 -> 양방향 표시 안함
 */


/*
 dfs 사용 - 자기 혼자서만 있어도 무리이기때문에 dfs 로 가능한 경로 파악
 1~n 까지 for 문으로 num[] 를 채움 - ans ++
 
 
 */
void dfs(int x){
    for(int i=1; i<=n; i++){
        // 가능한 연결이 있으면서 한번도 사용되지 않은 i -> 무리로 연결지을수 있다
        if(map[x][i] && !num[i]) { num[i] = true; dfs(i);}
    }
}
int main(){
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        int m;
        ans = 0;
        cin>>n>>m;
        
        
        for(int i=1; i<=n; i++) {num[i] = false; for(int j=1; j<=n; j++) map[i][j] = false;}
        
        for(int i=0; i<m; i++){
            int fir,sec;
            cin>>fir>>sec;
            // 서로 알고 있기 때문에 (양방향)
            map[fir][sec] = true; map[sec][fir] = true;
        }
        
        
        
        
        for(int i=1; i<=n; i++) {
            if(!num[i]) { num[i] = true; dfs(i); ans++;}
        }
        cout<<"#"<<t<<" "<<ans<<endl;
        
        
    }
}


