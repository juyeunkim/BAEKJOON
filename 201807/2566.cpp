/*
9×9 격자판에 쓰여진 81개의 자연수가 주어질 때, 이들 중 최댓값을 찾고 그 최댓값이 몇 행 몇 열에 위치한 수인지 구하는 프로그램을 작성하시오.
*/


#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int> > m(9, vector<int>(9,0));
    vector<int>::iterator it;
    int max = 0,x=0,y=0;
    
    for(int i=0;i<9; i++){
        for(int j=0; j<9; j++)
            cin>>m[i][j];
        
        if(max < *max_element(m[i].begin(), m[i].end())){
            x = i;
            y = max_element(m[i].begin(),m[i].end()) - m[i].begin();
            max = *max_element(m[i].begin(), m[i].end());
            
        }
        
        
    }
    
    
    cout<<max<<endl<<x+1<<" "<<y+1;
    
    return 0;
}

