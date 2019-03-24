#include <iostream>
#include <string.h>

using namespace std;


int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int map[51][51];
int possible[51][51]; // 같은 영역끼리 묶음
int sum[100001][2]; // 0 은 값, 1은 개수
int n,l,r, ans =0;


void dfs(int x, int y, int num){
    int sub;
    
    for(int i=0; i<4; i++){
        int xx = x+dx[i];
        int yy = y+dy[i];
        
        // 범위 확인
        if(xx<1 || yy<1 || xx>n || yy>n || possible[xx][yy] ==num) continue;
        
        
        sub = abs(map[x][y] - map[xx][yy]);
        
        // 뺀값이 범위안에 존재
        if(sub >= l && sub <= r){
            // sum[][0] - map의 합 저장
            // sum[][1] - 몇개가 들어가는지 저장
            sum[num][0] += map[xx][yy];
            sum[num][1]++;
            
            // 같은 영역을 묶음
            possible[x][y] = num;
            possible[xx][yy] = num;
            dfs(xx, yy, num);

        }
        
    }
}

void calc(int num){
    for(int a=1; a<=num; a++){
        // 값을 다 더해서 나눔 -> 평균
        int plus = sum[a][0] / sum[a][1];
        
        for(int i = 1; i<=n; i++){
            for(int j=1; j<=n; j++){
                // 같은 영역에 평균값 저장
                if(possible[i][j] == a) map[i][j] = plus;
            }
        }
    }
}

void init(){
    // 초기화
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            possible[i][j] = 0;
        }
    }
    
    for(int i=1; i<=10001; i++){
        sum[i][0] = 0; sum[i][1] = 0;
    }
    
    
}
int main(){
    cin>>n>>l>>r;
    int tmp,num = 1;
    
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>map[i][j];
            possible[i][j] = 0;
        }
    }
    
    while(1){
        num=1;
        init();
        
        tmp = ans;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(possible[i][j]==0) {
                    dfs(i,j,num);
                    if(sum[num][1] !=0){
                        sum[num][0] += map[i][j]; sum[num][1]++;
                        num++;
                    }
                }
            }
        }
        
        num--;
        // num == 0 -> 달라진 부분이 없다
        if(num == 0) break;
        
        calc(num);
        ans++;
        
    }
    
    cout<<ans<<endl;
    
    return 0;
}
