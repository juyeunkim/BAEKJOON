#include <iostream>

using namespace std;

int N;
int col[10];
int result = 0;

bool promising(int i)
{
    for(int j=0;j<i;j++)
    {
        // 새로운 퀸과 기존의 퀸이 같은 행에 있거나 대각선에 있을 경우
        if(col[j] == col[i] || abs(col[i]-col[j]) == (i-j))
            return false;
    }
    return true;
}
void N_Queen(int i)
{
    if(i == N)
        result ++;
    else
    {
        for(int j=0;j<N;j++)
        {
            col[i] = j;
            if(promising(i))
                N_Queen(i+1);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    
    for(int a=1; a<=t; a++){
        cin>>N;
        
        // 초기화
        result = 0;
        for(int i=0; i<10; i++)
            col[i] = 0;
        
        N_Queen(0);
        
        cout<<"#"<<a<<" "<<result<<endl;
    }
    
    return 0;
}
