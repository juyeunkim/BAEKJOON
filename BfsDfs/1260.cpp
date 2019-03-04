/*
- 입력
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 
정점 번호는 1번부터 N번까지이다.

- 
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. 
V부터 방문된 점을 순서대로 출력하면 된다.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,v;
bool visited[1001][1001];
bool check[1001];
int map[1001][1001];
vector<int> arr1;
vector<int> arr2;


void dfs(int x){
    
    for(int i=1; i<=n; i++){
        if(map[x][i]==1 && (!visited[x][i]) && !check[i]){
            arr1.push_back(i);
            check[i] = 1;
            visited[x][i] = 1;visited[i][x] = 1;
            dfs(i);
            
        }
    }
    
}

void bfs(int x, vector<int> tmp){
    for(int i=1; i<=n; i++){
        if(map[x][i]==1  && (!visited[x][i]) && !check[i]){
            tmp.push_back(i);
            check[i]=1;
            visited[x][i] = 1;visited[i][x] = 1;
        }
    }
    if(!tmp.empty()){
        int input = tmp[0];
        arr2.push_back(input);
        tmp.erase(tmp.begin());
        bfs(input, tmp);
    }
}

int main(){
    vector<int> tmp;
    cin>>n>>m>>v;
    int fir, sec;
    
    for(int i=1; i<=m; i++){
        cin>>fir>>sec;
        map[fir][sec] = 1;map[sec][fir] = 1;
    }
    
    arr1.push_back(v);
    check[v]=1;
    dfs(v);
    
    for(int i=0; i<arr1.size(); i++)
        cout<<arr1[i]<<" ";
    cout<<endl;
    
    for(int i=1; i<=n; i++)
        check[i] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            visited[i][j] = 0;
    }
    
    arr2.push_back(v);
    check[v]=1;
    bfs(v,tmp);
    for(int i=0; i<arr2.size(); i++)
        cout<<arr2[i]<<" ";
    
    return 0;
}
