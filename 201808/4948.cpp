/*
베르트랑 공준은 임의의 자연수 n에 대하여, n보다 크고, 2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.

이 명제는 조제프 베르트랑이 1845년에 추측했고, 파프누티 체비쇼프가 1850년에 증명했다.

예를 들어, 10보다 크고, 20보다 작거나 같은 소수는 4개가 있다. (11, 13, 17, 19) 또, 14보다 크고, 28보다 작거나 같은 소수는 3개가 있다. (17,19, 23)

n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오. 
*/

#include <iostream>
using namespace std;

int main(){
    int n = -1;
    while(1){
        cin>>n;
        int cnt = 0;
        if(n==0) break;
        
        int arr[250000]={0,};
        // 배열 초기화
        for(int i=2; i<=2*n; i++)
            arr[i] = i;
        
        for(int i=2; i<=2*n; i++){
            if(arr[i]==0) continue;
            // i의 배수
            for(int j= i+i; j<=2*n; j+=i){
                arr[j] = 0;
            }
        }
        
        for(int i=n+1; i<=2*n; i++){
            //cout<<arr[i]<<" ";
            if(arr[i]!=0) cnt++;
        }
        
        cout<<cnt<<endl;
        
        
        
    }
    return 0;
}
