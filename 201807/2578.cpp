/*
 2578
 첫째 줄부터 다섯째 줄까지 빙고판에 쓰여진 수가 가장 위 가로줄부터 차례대로 한 줄에 다섯 개씩 빈 칸을 사이에 두고 주어진다. 여섯째 줄부터 열째 줄까지 사회자가 부르는 수가 차례대로 한 줄에 다섯 개씩 빈 칸을 사이에 두고 주어진다. 빙고판에 쓰여진 수와 사회자가 부르는 수는 각각 1부터 25까지의 수가 한 번씩 사용된다.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    vector<vector<int> > bingo(5, vector<int>(5,0));
    vector<int>::iterator it;
    int host[25];
    int count = 0, index = 0;
    size_t diff;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>bingo[i][j];
            
        }
    }
    
     for(int i=0; i<25; i++){
     cin>> host[i];
     }
    
    while(1){
        
        int a;
        for(a=0; a<5; a++){
            // a번째 행에서 host[index]값이 있는지 확인하고, 배열의 자리값에 -1 대입
            it = find(bingo[a].begin(), bingo[a].end(),host[index]);
            diff = ( size_t) std::distance( bingo[a].begin(), it);
            // i번째 행에서 host[index] 존재
            if(diff != 5){
                bingo[a][diff] = -1;
                break;
            }
        }
        // 현재 위치에서 행,열,대각선 비교해서 -1값이 5개있으면 count증가
        //cout<<" a "<<a<<" diff "<<diff<<endl;
        // 행비교
        for(int i=0; i<5;i++){
            if(bingo[a][i]!=-1) break;
            else if(i==4 && bingo[a][i]==-1) count++;
        }
        // 열비교
        for(int i=0; i<5;i++){
            if(bingo[i][diff]!=-1) break;
            else if(i==4 && bingo[i][diff]==-1) count++;
        }
        // 대각선비교
        if(a==diff){
            for(int i=0;i<5;i++){
                if(bingo[i][i]!=-1) break;
                else if(i==4 && bingo[i][i]==-1) count++;
            }
        }
        if(a+diff==4){
            for(int i=0;i<5;i++){
                if(bingo[i][4-i]!=-1) break;
                else if(i==4 && bingo[i][4-i]==-1) count++;
            }
        }
        
        index++;
        if(count>=3) break;
        
    }
    
    cout<<index;
    
    return 0;
}

