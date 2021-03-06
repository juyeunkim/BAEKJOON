/*

n*n의 크기의 대나무 숲이 있다. 욕심쟁이 판다는 어떤 지역에서 대나무를 먹기 시작한다. 
그리고 그 곳의 대나무를 다 먹어 치우면 상, 하, 좌, 우 중 한 곳으로 이동을 한다. 그리고 또 그곳에서 대나무를 먹는다. 
그런데 단 조건이 있다. 이 판다는 매우 욕심이 많아서 대나무를 먹고 자리를 옮기면 그 옮긴 지역에 그 전 지역보다 대나무가 많이 있어야 한다. 
만약에 그런 지점이 없으면 이 판다는 불만을 가지고 단식 투쟁을 하다가 죽게 된다(-_-)

이 판다의 사육사는 이런 판다를 대나무 숲에 풀어 놓아야 하는데, 어떤 지점에 처음에 풀어 놓아야 하고, 
어떤 곳으로 이동을 시켜야 둘 다 소중한 생명이지만 판다가 최대한 오래 살 수 있는지 고민에 빠져 있다. 우리의 임무는 이 사육사를 도와주는 것이다. 
n*n 크기의 대나무 숲이 주어져 있을 때, 이 판다가 최대한 오래 살려면 어떤 경로를 통하여 움직여야 하는지 구하여라.
*/


#include <iostream>
#include <algorithm>

int dp[502][502];
int day[502][502];
int n;
using namespace std;


int panda(int x, int y){
    int pivot = dp[x][y];
    if(x<=0 || y<=0 || x>n || y>n) return -1;
    else if(day[x][y]!= -1)
        return day[x][y];
    else {
        day[x][y] = 1;
    
        if(pivot < dp[x-1][y]) day[x][y] = max(day[x][y],panda(x-1, y)+1);
        if(pivot < dp[x+1][y]) day[x][y] = max(day[x][y],panda(x+1, y)+1);
        if(pivot < dp[x][y-1]) day[x][y] = max(day[x][y],panda(x, y-1)+1);
        if(pivot < dp[x][y+1]) day[x][y] = max(day[x][y],panda(x, y+1)+1);
        
        return day[x][y];
    }
    
}
int main(){
    int ans =-1;
    cin>>n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>dp[i][j];
            day[i][j] = -1;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            ans = max(ans, panda(i,j));
        }
    }
    
    cout<<ans<<endl;
    return 0;
}

