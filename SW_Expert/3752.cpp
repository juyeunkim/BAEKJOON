#include<iostream>

using namespace std;


int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        bool check[10001];
        for(int i=0; i<10001; i++)
            check[i] = false;
        int input,sum = 0,n;
        int ans = 1;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>input;
            
            // 이미 계산된 값에 자신의 값 더함
            for(int j=sum; j>0; j--){
                
                if(check[j]) {
                    // 맨처음 들어가는것을 계산하기 위함(count)
                    if(!check[j+input]) ans++;
                    check[j+input]=true;
                }
            }
            
            if(!check[input]) ans++;
            check[input] = true;
            
            sum += input;
        }
        
        cout<<"#"<<test_case<<" "<<ans<<endl;
        
        
    }
    return 0;
}
