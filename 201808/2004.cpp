/*
nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <algorithm>
using namespace std;

long long two(long long num){
    long long t = 0;
    for(long long i = 2; i<=num; i=i*2)
        t += num / i;
    
    return t;
}

long long five(long long num){
    long long f = 0;
    for(long long i = 5; i<=num; i=i*5)
        f += num / i;
    
    return f;
}
int main(){
    long long n,m;
    cin>>n>>m;
    long long t = two(n) - (two(m)+two(n-m));
    long long f = five(n) - (five(m)+five(n-m));
    
    cout<<min(t,f)<<endl;
    
    return 0;
}
