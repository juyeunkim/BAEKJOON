#include <iostream>
#include <string>
using namespace std;

int n;
int ind, result;
int map[20][20];
int ans[20][20];

/*
 left() : 0 번째 열부터 n-1 번째 값을 비교해서 같은 값이면 더해서 ans 에 저장
 right() : n-1 번째 열부터 0번째
 up() : 0 번째 행부터 n-1 번째
 down() : n-1번째 행부터 0 번째
 
 1) map[i][j] 가 0 아니면 result 에 저장
 2) result와 다음번째 map[i][j]를 비교해서 같은 값으면
 더해서 ans 배열에 저장 , index ++, result = -1로 초기화
                                        다르면
 result 를 ans 배열에 저장, result = map[i][j]
 
 3) for을 다 돌고, 남는 result 값이 있으면 ans에 저장
 */
void l(){
    for(int i=0; i<n; i++){
        
        ind = 0; result = -1;
        for(int j=0; j<n; j++){
            if(map[i][j]!=0){
                // 1)
                if(result == -1){
                    result = map[i][j];
                    continue;
                }
                // 2)
                if(result == map[i][j]){
                    ans[i][ind] = result+map[i][j]; ind++;
                    result = -1;
                }
                else{
                    ans[i][ind] = result; ind++;
                    result = map[i][j];
                }
            }
        }
        // 3)
        if(result!=-1){
            ans[i][ind] = result;
        }
        
        
    }
}

void r(){
    for(int i=0; i<n; i++){
        ind = n-1; result  = -1;
        
        for(int j=n-1; j>=0; j--){
            if(map[i][j]!=0){
                if(result == -1){
                    result = map[i][j];
                    continue;
                }
                
                if(result == map[i][j]){
                    ans[i][ind] = result+map[i][j]; ind--;
                    result = -1;
                }
                else{
                    ans[i][ind] = result; ind--;
                    result = map[i][j];
                }
            }
        }
        if(result!=-1){
            ans[i][ind] = result;
        }
        
    }
}

void u(){
    
    // j는 행 i는 열
    for(int j=0; j<n; j++){
        ind = 0; result  = -1;
        for(int i=0; i<n; i++){
            if(map[i][j]!=0){
                if(result == -1){
                    result = map[i][j];
                    continue;
                }
                
                if(result == map[i][j]){
                    ans[ind][j] = result+map[i][j]; ind++;
                    result = -1;
                }
                else{
                    ans[ind][j] = result; ind++;
                    result = map[i][j];
                }
                
            }
        }
        if(result!=-1){
            ans[ind][j] = result;
        }
    }
}

void d(){
    for(int j=0; j<n; j++){
        ind = n-1; result  = -1;
        for(int i=n-1; i>=0; i--){
            if(map[i][j]!=0){
                if(result == -1){
                    result = map[i][j];
                    continue;
                }
                
                if(result == map[i][j]){
                    ans[ind][j] = result+map[i][j]; ind--;
                    result = -1;
                }
                else{
                    ans[ind][j] = result; ind--;
                    result = map[i][j];
                }
                
            }
        }
        if(result!=-1){
            ans[ind][j] = result;
        }
    }
}
int main(){
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        string dir;
        cin>>n>>dir;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){cin>>map[i][j]; ans[i][j] = 0;}
        }
        
        if(dir == "up") u();
        else if(dir == "down") d();
        else if(dir == "left") l();
        else r();
        
        cout<<"#"<<t<<endl;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){cout<<ans[i][j]<<" ";}
            cout<<endl;
        }
    }
}


