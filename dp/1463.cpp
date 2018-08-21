/*
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.
*/

#include <iostream>

using namespace std;

long long dp[1000001];

int main(){
    long long n;
    cin>>n;
    
    dp[2] = 1;
    for(int i=3; i<=n; i++){
        long long a[3]={100,100,100};
        
        if(i%3==0)
            a[0] = dp[i/3] + 1;
        if(i%2==0)
            a[1] = dp[i/2] + 1;
        a[2] = dp[i-1] + 1;
        
        //cout<< i<<" "<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
        
        dp[i] = min(min(a[0],a[1]),a[2]);
    }
    
    cout<<dp[n]<<endl;
    return 0;
}
