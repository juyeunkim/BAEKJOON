/*
봉우리가 여러개인 산 모양을 출력한다. 산 모양은 그림과 같고 좌우 대칭이다.

예제 입력
3
예제 출력
1213121
 
예제 입력
5
예제 출력
1213121412131215121312141213121
*/


#include <iostream>

using namespace std;
void mountain(int n){
    if(n==0) return;
    
    mountain(n-1);
    cout<<n;
    mountain(n-1);
    
}

int main(){
    int n;
    cin>>n;
    
    mountain(n);
    return 0;
}
