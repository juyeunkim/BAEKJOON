/*
다솜이는 은진이의 옆집에 새로 이사왔다. 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.

다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다. 
다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, ans=1;
    int num[10]={0,};
    cin>>n;
    
    while(n>0){
        num[n%10]++;
        n = n / 10;
    }
    num[6] += num[9];
    num[9] = 0;
    if(num[6] % 2 != 0) num[6]++;
    num[6] /= 2;
    for(int i=0; i<10; i++)
        ans = max(ans, num[i]);
    cout<<ans<<endl;
    return 0;
}