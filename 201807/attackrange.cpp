/*
윤성이는 어렸을 적부터 수없이 몰려오는 적으로부터 기지를 방어하는 디펜스 유형의 게임을 플레이하는 것을 좋아했다. 그래서 간단한 디펜스 게임을 만들어 보려고 한다.
당신은 윤성이를 도와, 디펜스 게임 내에서 플레이어가 설치하는 유닛의 사거리를 나타내는 기능을 구현하면 된다.  
입력


입력 첫째 줄에는 디펜스 게임의 맵 크기 N이 주어딘다. 맵은 N×N 크기의 2차원 형태이다. (N은 6이상 100이하의 짝수)
둘째 줄에는 유닛이 설치될 위치 X, Y와 유닛의 사거리 R이 주어진다. X는 행의 번호, Y는 열의 번호를 의미한다. (X, Y는 1이상 N이하의 자연수, R은 N/2이하의 자연수)
*/

#include <iostream>
#include <string>

using namespace std;

char map[102][102];

void crossroad(int i, int j, char r, char f){
    if(f == r || (i<=0 || i>100 || j<=0 || j>100))
        return;
    
    //cout<<"i "<<i<<" j "<<j<<" f "<<f<<" r "<<r<<endl;
    
    //상
    if(map[i-1][j]=='0') map[i-1][j] = f;
    //하
    if(map[i+1][j]=='0') map[i+1][j] = f;
    //좌
    if(map[i][j-1]=='0') map[i][j-1] = f;
    //우
    if(map[i][j+1]=='0') map[i][j+1] = f;
    
        
    crossroad(i-1, j, r, f+1);crossroad(i+1, j, r, f+1);crossroad(i, j-1, r, f+1);crossroad(i, j+1, r, f+1);
    
}


int main(){
    
    int n,x,y;
    char r;
    cin>>n>>x>>y>>r;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            map[i][j] = '0';
    }
    map[x][y]= 'x';
    
    crossroad(x, y, r+1, '1');
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cout<<map[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}


