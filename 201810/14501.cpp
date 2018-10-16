/*
상담원으로 일하고 있는 백준이는 퇴사를 하려고 한다.

오늘부터 N+1일째 되는날 퇴사를 하기 위해서, 남은 N일 동안 최대한 많은 상담을 하려고 한다.

백준이는 비서에게 최대한 많은 상담을 잡으라고 부탁을 했고, 비서는 하루에 하나씩 서로 다른 사람의 상담을 잡아놓았다.

각각의 상담은 상담을 완료하는데 걸리는 기간 Ti와 상담을 했을 때 받을 수 있는 금액 Pi로 이루어져 있다.
백준이가 얻을 수 있는 최대 수익을 구하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, ans=0;
    int t[16];
    int p[16];
    int dp[16];
    cin>>n;
    
    for(int i=1; i<=n; i++){
        cin>> t[i]>>p[i];
        if(i+t[i] > n+1) p[i] = -99999999;
        dp[i] = p[i];
    }
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            if(i-j >= t[j]) dp[i] = max(p[i] + dp[j], dp[i]);
        }
    }
    
    for(int i=1; i<=n; i++){
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
