/*
체스에서 룩이라는 기물은 상, 하, 좌, 우 방향으로 막혀있지만 않으면 움직일 수 있다.

체스는 킹만 잡히면 지게 되는 게임이다. 그 중에서도 알랩이는 룩으로 인해 게임을 지는 것을 극도로 싫어한다!
현재 체스판의 상태가 주어져 있고, 다음 차례가 상대의 차례일 때, 킹이 룩에게 잡힐 가능성이 있는지 알아보자
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int chess[8][8];
    vector<int> x;
    vector<int> y;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin>>chess[i][j];
            if(chess[i][j]==2) {
                x.push_back(i); y.push_back(j);
            }
        }
    }
    
    for(int i=0; i<x.size(); i++){
        //상 - x값 감소
        for(int j=x[i]; j>=0; j--){
            if(chess[j][y[i]] == 3) break;
            else if(chess[j][y[i]] == 1){
                cout<<1; return 0;
            }
        }
        //하 -  x값 증가
        for(int j=x[i]; j<8; j++){
            if(chess[j][y[i]] == 3) break;
            else if(chess[j][y[i]] == 1){
                cout<<1; return 0;
            }
        }
        //좌 - y값 감소
        for(int j=y[i]; j>=0; j--){
            if(chess[x[i]][j] == 3) break;
            else if(chess[x[i]][j] == 1){
                cout<<1; return 0;
            }
        }
        //우 - y값 증가
        for(int j=y[i]; j<8; j++){
            if(chess[x[i]][j] == 3) break;
            else if(chess[x[i]][j] == 1){
                cout<<1; return 0;
            }
        }
    }
    
    cout<<0;
    return 0;
}

