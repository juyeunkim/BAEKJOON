/*
RGB거리에 사는 사람들은 집을 빨강, 초록, 파랑중에 하나로 칠하려고 한다. 또한, 그들은 모든 이웃은 같은 색으로 칠할 수 없다는 규칙도 정했다. 
집 i의 이웃은 집 i-1과 집 i+1이다. 처음 집과 마지막 집은 이웃이 아니다.

각 집을 빨강으로 칠할 때 드는 비용, 초록으로 칠할 때 드는 비용, 파랑으로 드는 비용이 주어질 때, 
모든 집을 칠할 때 드는 비용의 최솟값을 구하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int dp[1001][3];
    int n, m;
    cin>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++)
            cin>>dp[i][j];
    }
    
    for(int i=1; i<n; i++){
        dp[i][0] += min(dp[i-1][1],dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0],dp[i-1][2]);
        dp[i][2] += min(dp[i-1][0],dp[i-1][1]);
    }
    
    
    m= min(min(dp[n-1][0],dp[n-1][1]), dp[n-1][2]);
    cout<<m<<endl;
    
    return 0;
}
