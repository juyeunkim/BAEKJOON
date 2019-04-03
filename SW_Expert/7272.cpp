#include <iostream>
#include <string>
using namespace std;

int range(char a, char b){
    if(a=='B' && b=='B') return 0;
    else if((a=='A' || a=='D' || (a>='O' && a<='R')) && (b=='A' || b=='D' || (b>='O' && b<='R')) ) return 2;
    else if((a=='C' || (a>='E' && a<='N') || (a>='S' && a<='Z')) && (b=='C' || (b>='E' && b<='N') || (b>='S' && b<='Z'))) return 4;
    return -1;
}

int main(){
    int n;
    string fir,sec;
    bool ans = false;
    cin>>n;
    
    for(int t=1; t<=n; t++){
        cin>>fir>>sec;
        
        if(fir.length()!=sec.length()) ans = false;
        else{
            for(int i=0; i<fir.length(); i++){
                //cout<<i<<endl;
                
                int tmp = range(fir[i], sec[i]);
                //cout<<i<<" "<<tmp<<endl;
                if(tmp==-1) {ans = false; break;}
                else if(tmp== 0 || tmp == 2 || tmp == 4) {
                    if(i==fir.length()-1) {ans = true;}
                    else continue;
                }
            }
        }
        
        cout<<"#"<<t<<" ";
        if(ans) cout<<"SAME"<<endl;
        else cout<<"DIFF"<<endl;
        
    }
    return 0;
}

