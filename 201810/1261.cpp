/*
알고스팟 운영진이 모두 미로에 갇혔다. 미로는 N*M 크기이며, 총 1*1크기의 방으로 이루어져 있다. 미로는 빈 방 또는 벽으로 이루어져 있고, 빈 방은 자유롭게 다닐 수 있지만, 벽은 부수지 않으면 이동할 수 없다.

알고스팟 운영진은 여러명이지만, 항상 모두 같은 방에 있어야 한다. 즉, 여러 명이 다른 방에 있을 수는 없다. 어떤 방에서 이동할 수 있는 방은 상하좌우로 인접한 빈 방이다. 즉, 현재 운영진이 (x, y)에 있을 때, 이동할 수 있는 방은 (x+1, y), (x, y+1), (x-1, y), (x, y-1) 이다. 단, 미로의 밖으로 이동 할 수는 없다.

벽은 평소에는 이동할 수 없지만, 알고스팟의 무기 AOJ를 이용해 벽을 부수어 버릴 수 있다. 벽을 부수면, 빈 방과 동일한 방으로 변한다.

만약 이 문제가 알고스팟에 있다면, 운영진들은 궁극의 무기 sudo를 이용해 벽을 한 번에 다 없애버릴 수 있지만, 안타깝게도 이 문제는 Baekjoon Online Judge에 수록되어 있기 때문에, sudo를 사용할 수 없다.

현재 (1, 1)에 있는 알고스팟 운영진이 (N, M)으로 이동하려면 벽을 최소 몇 개 부수어야 하는지 구하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <algorithm>

using namespace std;

char map[101][101];
bool visited[101][101]={false,};
int mi[101][101] = {0,};
int n,m;
// m 가로 n 세로

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void dfs(int x, int y, int cnt){
    
    cout<<" x "<<x<<" y "<<y<<" cnt "<<cnt<<endl;
    
    if(mi[x][y] <= cnt) return;
    else mi[x][y] = cnt;
    
    if(x == m && y == n) return;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx <1 || ny < 1 || nx >m || ny > n) continue;
        if(visited[nx][ny]) continue;
        
        visited[nx][ny] = true;
        if(map[nx][ny]=='1') dfs(nx, ny, cnt+1);
        else dfs(nx, ny, cnt);
        visited[nx][ny] = false;
    }
    
}
int main(){
    cin>>n>>m;
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin>>map[i][j];
            mi[i][j] = 2147483647;
        }
    }
    
    visited[1][1] = true;
    dfs(1,1,0);
    
    cout<<mi[m][n]<<endl;
    return 0;
}


