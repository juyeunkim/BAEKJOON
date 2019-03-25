#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001];
int compo[1001];
int n;

void bfs(int s, int v){
    queue<int> q;
    q.push(s);
    compo[s] = v;
    
    int next ;
    
    while(!q.empty()){
        next = q.front();
        q.pop();
        
        for(int i=1; i<=n;i++){
            if(map[next][i] == 1 && compo[i] == 0) {q.push(i); compo[i] = v;}
        }
    }
    
}

int main(){
    int m, cnt = 1;
    int fir, sec;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        compo[i] = 0;
        for(int j=1; j<=n; j++)
            map[i][j] = 0 ;
    }
    
    for(int i=1; i<=m; i++){
        cin>>fir>>sec;
        map[fir][sec] = 1; map[sec][fir] = 1;
    }
    
    for(int i=1; i<=n; i++){
        if(compo[i]==0) {bfs(i,cnt++);}
    }
    
    cout<<--cnt;
    
    
    
    return 0;
}
