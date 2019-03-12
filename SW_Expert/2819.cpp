#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[5][5];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool check[10000000];
int ans = 0;


void dfs(int x, int y,int cnt ,int s){
    int tmp = s*10 + arr[x][y];
    cnt ++;
    
    if(cnt > 7) {
        //cout<<x<<" "<<y<<" "<<s<<endl;
        // 가장 먼저 확인
        if(!check[s]) ans++;
        check[s] = true; return;
    }
    
    for(int i=0; i<4; i++){
        if(x+dx[i] <=0 || y+dy[i] <=0 || x+dx[i] >4 || y+dy[i]>4) continue;
        dfs(x+dx[i], y+dy[i], cnt, tmp);
    }
}

int main(){
    int n;
    
    
    cin>>n;
    
    for(int t = 1; t<=n; t++){
        
        ans = 0;
        
        for(int i=1; i<=4; i++){
            for(int j=1; j<=4; j++){
                cin>>arr[i][j];
            }
        }
        
        for(int i=0; i<10000000; i++) check[i] = false;
        
        for(int i=1; i<=4; i++){
            for(int j=1; j<=4; j++){
                dfs(i, j,0,0);
            }
        }
        
        cout<<"#"<<t<<" "<<ans<<endl;
    }
    
    
    return 0;
}
