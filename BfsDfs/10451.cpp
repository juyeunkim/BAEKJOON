/*
1부터 N까지 정수 N개로 이루어진 순열을 나타내는 방법은 여러 가지가 있다. 
예를 들어, 8개의 수로 이루어진 순열 (3, 2, 7, 8, 1, 4, 5, 6)을 배열을 이용해 표현하면 
 
 와 같다. 또는, Figure 1과 같이 방향 그래프로 나타낼 수도 있다.

순열을 배열을 이용해 
 
 로 나타냈다면, i에서 πi로 간선을 이어 그래프로 만들 수 있다.

Figure 1에 나와있는 것 처럼, 순열 그래프 (3, 2, 7, 8, 1, 4, 5, 6) 에는 총 3개의 사이클이 있다. 이러한 사이클을 "순열 사이클" 이라고 한다.

N개의 정수로 이루어진 순열이 주어졌을 때, 순열 사이클의 개수를 구하는 프로그램을 작성하시오.
*/


#include <iostream>

using namespace std;

bool check[1001];
int ans;

void correct(int map[], int target,int s){
    
    check[s] = true;
    if(map[s] == target) {ans++;}
    else correct(map, target, map[s]);
}

int main(){
    int n,c,input;
    cin>>n;

    
    for(int i=0; i<n; i++){
        cin>>c;
        int map[c+1];
        ans = 0;
        for(int j=1; j<=c; j++){
            cin>>input;
            map[j] = input;
        }
        
        for(int j=1; j<=c; j++)
            check[j]= false;
        
        for(int j=1; j<=c; j++){
            if(!check[j]) correct(map, j, map[j]);
        }
        
        cout<<ans<<endl;
        
    }
    
    
    return 0;
}
