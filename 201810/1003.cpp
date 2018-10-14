/*
N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;

int zero[41][2];

// 0이 출현되는 횟수, 1이 출현되는 횟수
int main(){
    int n, fib;
    cin>>n;
    
    for(int i=0; i<=40; i++){
        if(i == 0) {
            zero[0][0] = 1;zero[0][1] = 0;
        }
        else if(i==1){
            zero[1][0] = 0;zero[1][1] = 1;
        }
        else {
        zero[i][0] = zero[i-1][0] + zero[i-2][0];
        zero[i][1] = zero[i-1][1] + zero[i-2][1];
        }
    }
    for(int i=0; i<n; i++){
        cin>>fib;
        cout<<zero[fib][0]<<" "<<zero[fib][1]<<endl;
    }
    return 0;
}
