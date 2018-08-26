/*
적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.

크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다.
또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)

예를 들어, 그림이 아래와 같은 경우에

RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1) 하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)

그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int n;
int one = 0, two = 0;
char m[101][101];
bool visited[101][101]={false,};

void RGB(int x, int y, char c){
    if(x<=0 || x>n || y<=0 || y>n) return;
    
    if(!visited[x-1][y] && c == m[x-1][y]) {
        visited[x-1][y] = true;
        RGB(x-1, y, c);
    }
    if(!visited[x+1][y] && c == m[x+1][y]) {
        visited[x+1][y] = true;
        RGB(x+1, y, c);
    }
    if(!visited[x][y-1] && c == m[x][y-1]) {
        visited[x][y-1] = true;
        RGB(x, y-1, c);
    }
    if(!visited[x][y+1] && c == m[x][y+1]) {
        visited[x][y+1] = true;
        RGB(x, y+1, c);
    }
    
    
}
int main(){
    cin>>n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>m[i][j];
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!visited[i][j]) {RGB(i, j, m[i][j]);one++;}
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            visited[i][j] = false;
            if(m[i][j]=='G') m[i][j] = 'R';
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!visited[i][j]) {RGB(i, j, m[i][j]);two++;}
        }
    }
    
    cout<<one<<" "<<two<<endl;
    return 0;
}

