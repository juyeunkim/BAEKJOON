/*
직선으로 되어있는 도로의 한 편에 가로수가 임의의 간격으로 심어져있다. KOI 시에서는 가로수들이 모두 같은 간격이 되도록 가로수를 추가로 심는 사업을 추진하고 있다. 
KOI 시에서는 예산문제로 가능한 한 가장 적은 수의 나무를 심고 싶다.

편의상 가로수의 위치는 기준점으로 부터 떨어져 있는 거리로 표현되며, 가로수의 위치는 모두 양의 정수이다.

예를 들어, 가로수가 (1, 3, 7, 13)의 위치에 있다면 (5, 9, 11)의 위치에 가로수를 더 심으면 모든 가로수들의 간격이 같게 된다. 
또한, 가로수가 (2, 6, 12, 18)에 있다면 (4, 8, 10, 14, 16)에 가로수를 더 심어야 한다.

심어져 있는 가로수의 위치가 주어질 때, 모든 가로수가 같은 간격이 되도록 새로 심어야 하는 가로수의 최소수를 구하는 프로그램을 작성하라. 
단, 추가되는 나무는 기존의 나무들 사이에만 심을 수 있다.
*/

#include <iostream>
using namespace std;

// 최대공약수
int gcd(int x, int y){
    int n;
    while(1){
        n = x%y;
        if(n==0) return y;
        x=y; y=n;
    }
}

int main(){
    int n, g;
    int tree=0;
    cin>>n;
    int street[100000];
    int dist[100000];
    
    for(int i=0; i<n; i++){
        cin>> street[i];
        if(i!=0) dist[i-1] = street[i] - street[i-1];
    }
    
    g = dist[0];
    // dist에서 최대공약수 찾기
    for(int i=1; i<n-1; i++){
        g = gcd(g, dist[i]);
    }
    
    // 사이에 심을 나무개수 구하기
    for(int i=0; i<n-1; i++){
        tree += (dist[i] / g) -1;
    }
    
    cout<<tree<<endl;
    return 0;
}
