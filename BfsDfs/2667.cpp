/*
철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 
여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다.
<그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 
각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char map[26][26];
int visited[26][26];
int n;


int ddfs(int x, int y, int num){
    if(x <= 0 || y <= 0 || x >n || y > n) return 0;
    visited[x][y]=1;
    
    
    if(map[x-1][y] == '1' && visited[x-1][y]==0){
        visited[x-1][y] = 1;
        num = ddfs(x-1, y,num+1);
    }
    
    if(map[x+1][y] == '1' && visited[x+1][y]==0){
        visited[x+1][y] = 1;
        num = ddfs(x+1, y,num+1);
    }
    
    if(map[x][y-1] == '1' && visited[x][y-1]==0){
        visited[x][y-1] = 1;
        num = ddfs(x, y-1,num+1);
    }
    
    if(map[x][y+1] == '1' && visited[x][y+1]==0){
        visited[x][y+1] = 1;
        num = ddfs(x, y+1,num+1);
    }
    
    return num;
}
int main(){
    vector<int> ans;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cin>>map[i][j];
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(visited[i][j]==0 && map[i][j]=='1'){
                ans.push_back(ddfs(i, j, 1));
            }
            
        }
    }
    
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<endl;
    
    return 0;
}
