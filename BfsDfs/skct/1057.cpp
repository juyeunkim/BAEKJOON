#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, kim,im;
    int ans = 0, resut= -1;
    int range;
    bool even = false, check = false;
    cin>>n>>kim>>im;
    queue<int> q;
    
    for(int i=1; i<=n; i++)
        q.push(i);
    
    int tmp = kim;
    if(kim > im){
        kim = im;
        im = tmp;
    }
    
    while(!check){
        ans++;
        range = n/2;
        if(n%2!=0) {range +=1; even = false;}
        else even = true;
        n = range;
        for(int i=1; i<=range; i++){
            int fir = q.front(); q.pop();
            
            if(!even && i==range) {q.push(fir); break;}
            int sec = q.front(); q.pop();
            
            if(fir == kim && sec == im) {resut = ans; check = true; break;}
            
            if(sec == kim || sec == im) { q.push(sec);}
            else {q.push(fir);}
            
            
        }
        
        
    }
    cout<<resut<<endl;
    return 0;
}

