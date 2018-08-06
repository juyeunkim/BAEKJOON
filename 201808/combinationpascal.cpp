/*
n명의 사람중 m명을 순서에 상관없이 뽑는 경우의 수를 조합이라고 하며 nCm으로 나타낸다.
이 조합은 파스칼의 삼각형과 아주 밀접한 관련이 있다고 한다.
n과 m이 주어졌을때 nCm의 값을 출력하는 프로그램을 작성하시오
*/

#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int pascal[31][31]={0,};
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || j==i) pascal[i][j] = 1;
            else{
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
                if(i == n && j== m) break;
            }
        }
    }
    cout<<pascal[n][m]<<endl;
    
    return 0;
}
