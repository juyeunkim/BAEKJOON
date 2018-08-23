/*
무한 수열 A는 다음과 같다.

A[0] = 1;
A[i] = A[i/P] + A[i/Q] (i>=1, i/P또는 i/Q가 정수가 아닐 때는 가우스 기호를 이용한다. (가우스 기호, [3.4] = 3)을 이용한다.
N, P와 Q가 주어질 때, A[N]을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N P Q가 주어진다. N은 10^12보다 작거나 같은 자연수 또는 0이고, P와 Q는 2보다 크거나 같고, 10^9보다 작거나 같은 자연수이다.
*/


#include <iostream>
#include <map>

using namespace std;

// n의 범위가 크기 때문에 map 사용
map<long long, long long> a;

long long p,q;
long long forever(long long n){
    long long pp = n/p, qq = n/q;
    if(n==0 || n==1) return a[n];
    else if(a[pp]!=0 && a[qq]!=0) return a[pp]+a[qq];
    else {
        if(a[pp]==0) a[pp] = forever(pp/p) + forever(pp/q);
        if(a[qq]==0) a[qq] = forever(qq/p) + forever(qq/q);
    }
    a[n] = a[pp] + a[qq];
    return a[n];
}

int main(){
    long long n;
    cin>>n>>p>>q;
    
    a[0] = 1; a[1]=2;
    cout<<forever(n)<<endl;
    
    //for(int i=0; i<=n; i++)
    //    cout<<dp[i]<<" ";
    
    
    return 0;
}
