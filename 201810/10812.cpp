/*
도현이는 바구니를 총 N개 가지고 있고, 각각의 바구니에는 1번부터 N번까지 번호가 순서대로 적혀져 있다. 
바구니는 일렬로 놓여져 있고, 가장 왼쪽 바구니를 1번째 바구니, 그 다음 바구니를 2번째 바구니, ..., 가장 오른쪽 바구니를 N번째 바구니라고 부른다. 

도현이는 앞으로 M번 바구니의 순서를 회전시키려고 만드려고 한다. 
도현이는 바구니의 순서를 회전시킬 때, 순서를 회전시킬 범위를 정하고, 그 범위 안에서 기준이 될 바구니를 선택한다. 도현이가 선택한 바구니의 범위가 begin, end이고, 기준이 되는 바구니를 mid라고 했을 때, begin, begin+1, ..., mid-1, mid, mid+1, ..., end-1, end 순서로 되어있는 바구니의 순서를 mid, mid+1, ..., end-1, end, begin, begin+1, ..., mid-1로 바꾸게 된다.

바구니의 순서를 어떻게 회전시킬지 주어졌을 때, M번 바구니의 순서를 회전시킨 다음, 바구니에 적혀있는 번호를 가장 왼쪽 바구니부터 출력하는 프로그램을 작성하시오.
*/


#include <iostream>
using namespace std;


int main(){
    int n,m;
    int i,j,k;
    int arr[101];
    cin>>n>>m;
    
    for(int a=1; a<=n; a++) arr[a] = a;
    
    for(int a=1; a<=m; a++){
        int temp[101];
        cin>>i>>j>>k;
        int fir = 1, last;
        for(int b=i; b<k; b++) {
            temp[fir] = arr[b]; fir ++;
        }
        fir --;
        last = fir;
        fir = i;
        for(int b=k; b<=j; b++){
            arr[fir] = arr[b]; fir++;
        }
        for(int b=1; b<=last; b++){
            arr[fir] = temp[b]; fir++;
        }
    }
    
    for(int a=1; a<=n; a++) cout<<arr[a]<<" ";
    return 0;
}
