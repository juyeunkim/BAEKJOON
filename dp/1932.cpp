/*
맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 
아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int dp[501][501];
    int n,m;
    cin>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++)
            cin>>dp[i][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j==0)
                dp[i][j] += dp[i-1][j];
            else if(j==i)
                dp[i][j] += dp[i-1][j-1];
            else{
                dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }
    
    m = dp[n-1][0];
    for(int j=1; j<n; j++){
        if(m < dp[n-1][j]) m = dp[n-1][j];
    }
    
    cout<<m<<endl;
    return 0;
}
