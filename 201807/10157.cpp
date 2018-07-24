/*
10157
이 공연장에 입장하기 위하여 많은 사람이 대기줄에 서있다. 기다리고 있는 사람들은 제일 앞에서부터 1, 2, 3, 4, . 순으로 대기번호표를 받았다. 
우리는 대기번호를 가진 사람들에 대하여 (1,1)위치 좌석부터 시작하여 시계방향으로 돌아가면서 비어있는 좌석에 관객을 순서대로 배정한다. 이것을 좀 더 구체적으로 설명하면 다음과 같다.

먼저 첫 번째 사람, 즉 대기번호 1인 사람은 자리 (1,1)에 배정한다. 그 다음에는 위쪽 방향의 좌석으로 올라가면서 다음 사람들을 배정한다. 
만일 더 이상 위쪽 방향으로 빈 좌석이 없으면 오른쪽으로 가면서 배정한다. 오른쪽에 더 이상 빈자리가 없으면 아래쪽으로 내려간다. 
그리고 아래쪽에 더 이상 자리가 없으면 왼쪽으로 가면서 남은 빈 좌석을 배정한다. 이 후 왼쪽으로 더 이상의 빈 좌석이 없으면 다시 위쪽으로 배정하고, 이 과정을 모든 좌석이 배정될 때까지 반복한다. 
여러분은 공연장의 크기를 나타내는 자연수 C와 R이 주어져 있을 때, 대기 순서가 K인 관객에게 배정될 좌석 번호 (x,y)를 찾는 프로그램을 작성해야 한다. 
*/

#include <iostream>

using namespace std;

int main(){
    int c,r,k;
    int i=1,j=1, add = 1;
    
    cin>>c>>r>>k;
    
    
    if(k> c*r) cout<<0;
    else{
        while (1) {
            
            for(int a=1; a<=r; a++){
                if(i == 1 && a == r) break;
                if(k<=1) break;
                j += add; k--;
                
                
            }
            for(int a=1; a<=c-1; a++){
                if(k<=1) break;
                i += add; k--;
                
               
                
            }
            if(k<=1) break;
            add *= -1;
            r--; c--;
            
        }
        cout<<i<<" "<<j;
    }
    
    
    
    return 0;
}