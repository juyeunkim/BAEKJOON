/*
두 정수 n, k를 입력받아 k개의 1을 가진 n자리 이진 패턴을 출력하는 프로그램을 작성하세요.
*/

#include <iostream>
#include <string>

using namespace std;

int n,k;
void bin(string s){
    if(s.length()==n){
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(cnt > k ) break;
            else if(s[i]=='1') cnt++;
        }
        if(cnt == k)
            cout<<s<<endl;
        return;
    }
    
    bin(s+'1'); bin(s+'0');
    
}

int main(){
    cin>>n>>k;
    bin("");
    return 0;
}
