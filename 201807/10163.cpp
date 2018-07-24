/*
평면에 색깔이 서로 다른 직사각형 모양의 색종이 N장이 하나씩 차례로 놓여진다. 이 때 색종이가 비스듬하게 놓이는 경우는 없다. 
즉, 모든 색종이의 변은 서로 평행하거나, 서로 수직이거나 둘 중 하나이다.
N장의 색종이가 주어진 위치에 차례로 놓일 경우, 각 색종이가 보이는 부분의 면적을 구하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main(){
    int n;
    int x,y,w,h;
    int paper[101][101]={0,};
    int area[101]={0,};
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>x>>y>>w>>h;
        for(int j=x; j<x+w; j++){
            for(int k=y; k<y+h; k++){
                 paper[j][k] = i+1;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<101; j++){
            for(int k=0; k<101; k++){
                if(paper[j][k]==i+1) area[i]++;
            }
        }
        cout<<area[i]<<endl;
    }
    
    return 0;
}

