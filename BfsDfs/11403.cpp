/*
가중치 없는 방향 그래프 G가 주어졌을 때, 모든 정점 (i, j)에 대해서, i에서 j로 가는 경로가 있는지 없는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄부터 N개 줄에는 그래프의 인접 행렬이 주어진다. 
i번째 줄의 j번째 숫자가 1인 경우에는 i에서 j로 가는 간선이 존재한다는 뜻이고, 0인 경우는 없다는 뜻이다. 
i번째 줄의 i번째 숫자는 항상 0이다.

출력
총 N개의 줄에 걸쳐서 문제의 정답을 인접행렬 형식으로 출력한다. 정점 i에서 j로 가는 경로가 있으면 i번째 줄의 j번째 숫자를 1로, 없으면 0으로 출력해야 한다.
*/

#include <iostream>

using namespace std;

int n;
int graph[101][101];
int map[101][101];

void findpath(int i, int j){
    
    if(i==j) return;
    
    for(int k=1; k<=n; k++){
        if (graph[j][k]!=0 && !map[i][k]){
            map[i][k] = 1;
            findpath(i,k);
        }
    }
    
}

int main(){
    cin>>n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>graph[i][j];
            
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if (graph[i][j]!=0 && !map[i][j]){
                map[i][j] =1;
                findpath(i,j);
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cout<<map[i][j]<<" ";
        cout<<endl;
    }
    
    
    return 0;
}

