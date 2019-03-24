#include <iostream>
#include <string>

using namespace std;
int main(){
    string s;
    int ans =0;
    getline(cin,s);
    
    // 앞뒤 공백제거
    if(s[0] == ' ') s = s.substr(1);
    if(s[s.length()-1] == ' ') s = s.substr(0,s.length()-1);
    
    //cout<<s<<endl;
    
    for(int i=0; i<s.length(); i++){
        if(s[i]==' ') ans++;
    }
    if(s.length()!=0 ) ans++;
    cout<<ans;
    //cout<<s.length()<<" "<<s;
    return 0;
}
