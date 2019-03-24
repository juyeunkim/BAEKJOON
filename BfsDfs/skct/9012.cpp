#include <iostream>
#include <string>

using namespace std;
int main(){
    int n, cnt =0;
    string s, ans;
    cin>>n;
    
    for(int t=0; t<n; t++){
        cin>>s;
        cnt =0;
        
        for(int i=0; i<s.length(); i++){
            if(cnt < 0 ){ ans = "NO"; break;}
            if(s[i]=='(') cnt++;
            else if(s[i]==')')cnt --;
        }
        
        if(cnt !=0 ) ans = "NO";
        else ans = "YES";
        
        cout<<ans<<endl;
        
        
    }
    return 0;
}
